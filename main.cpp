#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}

// 242
class Solution1 {
public:
  bool isAnagram(string s, string t) {
   int flags[26] = {0};
   int flags2[26] = {0};
    for (int i = 0, len = s.size(); i < len; i++) {
        flags[s[i] - 'a']++;
    }
    for (int i = 0, len = t.size(); i < len; i++) {
        flags2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (flags[i] != flags2[i]) return false;
    }
    return true;
  }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        } else if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        } else {
            return root;
        }
    }
};
