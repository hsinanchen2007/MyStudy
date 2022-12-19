### 解题思路
用一个falge标志来判断是否要继续进行和进位
![image.png](https://pic.leetcode-cn.com/3c04029e403a85868eeac2c3c6e92a5aaaef60cd6e52a59c7cac514003e96505-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int falg=1;//判断是否要继续进行
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(falg==1)
            {
                digits[i]+=1;
                falg=digits[i]/10;
                digits[i]=digits[i]%10;
            }
        }
        if(falg==1)//判断第一位是否需要进位
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
```