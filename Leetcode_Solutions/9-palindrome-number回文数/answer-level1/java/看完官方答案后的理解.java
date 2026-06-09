### 解题思路
此处撰写解题思路
思路:翻转x后一半数据与x前一半数据对比，相等则是回文数。翻转的思路：先用%10求余数，后用/10求第二个余数，前一个余数*10+后一个余数实现翻转。奇数位的情况：翻转后/10消除最后一个奇数后与x对比。
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {

        if(x<0||(x%10==0&&x!=0))     //x小于0，和x各位数为0的情况，直接返回false 
        return false;

        int ans=0;
        while(x>ans){        //临界值，x>ans说明ans已经到达了x的一半
            ans = ans*10 + x%10;   //翻转x的一半，
            x= x/10;
        }

        return ans==x||x==ans/10; //当x的长度为奇数时，可以用/10的方法去掉奇数位
        
    }
}
```