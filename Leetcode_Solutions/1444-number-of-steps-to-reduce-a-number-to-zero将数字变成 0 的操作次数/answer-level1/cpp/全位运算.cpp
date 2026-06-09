仅仅抓住奇数最后一位一定为1 &1判断奇偶 若为奇数 就异或掉
```
class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num){
            if(num & 1){
                num ^= 1;
            }
            else{
                num >>= 1;
            }
            count++;
        }
        return count;
    }
};
```
