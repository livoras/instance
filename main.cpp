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

/**235
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

// 70
class Solution {
public:
    map <int, int> curry = {
        {1, 1}, {2, 2}
    };
    int climbStairs(int n) {
        int num = curry[n];
        if (num) return num;
        num = climbStairs(n - 2) + climbStairs(n - 1);
        curry[n] = num;
        return num;
    }
};

// 102
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    queue<TreeNode*> arr;
    arr.push(root);
    while (!arr.empty()) {
        vector<int> intes;
        queue<TreeNode*> next;
        while(!arr.empty()) {
            intes.push_back(arr.front() -> val);
            next.push(arr.front());
            arr.pop();
        }
        ret.push_back(intes);
        arr = next;
    }
    return ret;
}
