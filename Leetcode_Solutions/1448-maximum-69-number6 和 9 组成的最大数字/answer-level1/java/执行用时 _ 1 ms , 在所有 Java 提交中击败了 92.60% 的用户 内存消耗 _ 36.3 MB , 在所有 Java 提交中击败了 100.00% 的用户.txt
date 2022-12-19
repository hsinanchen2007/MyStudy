### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        ArrayList<Integer> re =  new ArrayList<>();
        while(num > 0){
            re.add(num % 10);
            num /= 10;
        }
        for(int i = re.size() - 1; i >= 0; i--){
            if(re.get(i) == 6){
                re.set(i, 9);
                break;
            }
        }
        int res = 0;
        for(int i = 0; i < re.size(); i++){
            res += re.get(i) * Math.pow(10, i);
        }
        return res;
    }
}
```