
![image.png](https://pic.leetcode-cn.com/c0c632ff119a4e1da54455da6f44bea45833916788ef4209ea7ee5d6ccc2bd56-image.png)
![8555249f20b206c28f6dd660e728523.png](https://pic.leetcode-cn.com/f45a30bef4a7bb388a4fb398412c3243079d8d8ac44ad17bd454faf9b64157f0-8555249f20b206c28f6dd660e728523.png)

class Solution {
public:
    string reverseLeftWords(string s, int n) {
   for (int i=0;i<n;i++)
    {
        s.push_back(s[i]);
    }
    s.erase(0,n);
      return s;

    }

    
};