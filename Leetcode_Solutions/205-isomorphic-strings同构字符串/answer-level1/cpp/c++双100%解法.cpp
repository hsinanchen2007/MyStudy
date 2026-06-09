### 解题思路
![TIM图片20200312091855.png](https://pic.leetcode-cn.com/c0b7030e501ac3c3d93c8a30bff72c428c9d1a5f906c080060c2c08eff19278e-TIM%E5%9B%BE%E7%89%8720200312091855.png)


### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int dic1[128];   //根据ASCII码，总共有128种字符
        int dic2[128];   //为两个字符串分别建立字典
        int i, j, k;    //辅助变量
        for(i = 0; i < 128; i++){
            dic1[i] = -1;
            dic2[i] = -1;
        }

        int len = s.size();
        j = 0, k = 0;
        int z, x;   //辅助变量

        for(i = 0; i < len; i++){
            if(dic1[s[i]] == -1){  //若这个字符在s没有出现过，则记录在字典上
                dic1[s[i]] = j;
                z = j++;
            }else{
                z = dic1[s[i]];    //若这个字符出现过，直接取值
            }

            if(dic2[t[i]] == -1){   //对t操作，同上
                dic2[t[i]] = k;
                x = k++;
            }else{
                x = dic2[t[i]];
            }
            if(z != x) return false;  //若两字符串格式相同，则z == x，否则返回false
        }
        return true;
    }
};
```