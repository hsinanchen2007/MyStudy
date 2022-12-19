### 解题思路
此处撰写解题思路
**双指针：left=0,right=s.length-1**
![Snipaste_2020-03-24_18-00-54.jpg](https://pic.leetcode-cn.com/00940db3ec5ad5e7109d40decfb3367c32a94f58f1ce84b2961b076efd39d84e-Snipaste_2020-03-24_18-00-54.jpg)

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int left=0,right=s.length-1;
        while(left<right){
            char t=s[left];
            s[left]=s[right];
            s[right]=t;
            left++;
            right--;
        }

    }
}
```