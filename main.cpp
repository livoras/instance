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


