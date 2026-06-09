### 解题思路
取模拆分数字，判断数字首尾是否对称

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        List<Integer> nums=new ArrayList();
        while(x>0){
            nums.add(x%10);
            x=x/10;
        }
        int half=(nums.size()+1)/2;
        for(int i=0;i<half;i++){
            if(nums.get(i)!=nums.get(nums.size()-1-i)){
                return false;
            }
        }
        return true;
    }
}
```