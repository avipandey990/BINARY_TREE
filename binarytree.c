#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode* root;
} BinaryTree;

TreeNode* create_tree_node(int data) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        printf("Memory not available");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode* insert_node(TreeNode* root, int data) {
    if (root == NULL) {
        return create_tree_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

int get_node_depth(TreeNode* root, int val, int depth) {
    if (root == NULL) {
        return -1;
    }
    if (val == root->data) {
        return depth;
    }
    if (val < root->data) {
        return get_node_depth(root->left, val, depth + 1);
    } else {
        return get_node_depth(root->right, val, depth + 1);
    }
}

int get_node_height(TreeNode* root, int val) {
    if (root == NULL) {
        return -1;
    }
    if (val == root->data) {
        return 0;
    }
    int left_height = get_node_height(root->left, val);
    int right_height = get_node_height(root->right, val);
    if (left_height == -1 && right_height == -1) {
        return -1;
    } else {
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

int in_order_traversal(TreeNode* root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        printf("%d ", root->data);
        in_order_traversal(root->right);
    }
    return 0;
}

int pre_order_traversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
    return 0;
}

int post_order_traversal(TreeNode* root) {
    if (root != NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->data);
    }
    return 0;
}

TreeNode* clone_tree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* new_node = create_tree_node(root->data);
    new_node->left = clone_tree(root->left);
    new_node->right = clone_tree(root->right);
    return new_node;
}

int main() {
    BinaryTree tree;
    tree.root = NULL;

    tree.root = insert_node(tree.root, 8);
    insert_node(tree.root, 3);
    insert_node(tree.root, 10);
    insert_node(tree.root, 6);
    insert_node(tree.root, 7);
    insert_node(tree.root, 1);
    insert_node(tree.root, 14);
    insert_node(tree.root, 13);    
    insert_node(tree.root, 4);

    printf("Inorder traversal: ");
    in_order_traversal(tree.root);
    printf("\n");

    printf("Preorder traversal: ");
    pre_order_traversal(tree.root);
    printf("\n");

    printf("Postorder traversal: ");
    post_order_traversal(tree.root);
    printf("\n");

    int n;
    printf("Enter a value to search: ");
    scanf("%d", &n);
    int depth = get_node_depth(tree.root, n, 0);
    int height = get_node_height(tree.root, n);
    if (depth == -1) {
        printf("Node with value %d not found in the tree.\n", n);
    } else {
        printf("Depth of node with value %d: %d\n", n, depth);
        printf("Height of node with value %d: %d\n", n, height);
    }

    BinaryTree cloned_tree;
    cloned_tree.root = clone_tree(tree.root);
    printf("\nCloned tree: Inorder traversal: ");
    in_order_traversal(cloned_tree.root);
    printf("\n");

    return 0;
}
