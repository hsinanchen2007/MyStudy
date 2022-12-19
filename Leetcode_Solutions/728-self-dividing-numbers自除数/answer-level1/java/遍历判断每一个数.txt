### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList<>();
        while(left <= right ){
            if(isOrNotDivid(left)){
                ans.add(left);
            }
            left++;
        }
        return ans;
    }
    private boolean isOrNotDivid(int n){
        int left = n;
        while(n != 0){
            int temp = n%10;
            if(temp == 0 || left % temp != 0){
                return false;
            }
            n /= 10;
        }
        return true;
    }
}
```