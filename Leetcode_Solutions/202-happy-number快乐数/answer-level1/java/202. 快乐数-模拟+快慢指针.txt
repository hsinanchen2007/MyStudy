

/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/28
 *
 * 解题思路1: 模拟求解 使用hashmap来确定出口,将history 都存在map中
 *
 * 解题思路2: 模拟求解 使用快慢指针来确定出口 当出现循环 快指针一定会追上慢指针 当不出现循环 快指针会在平方等于1的位置自循环(停止)1*1=1
 */

```
    public boolean isHappy(int n) {

        HashMap<Integer , Integer> hashMap = new HashMap<Integer, Integer>();

        int mod = 0;
        int res = 0;
        while(true){
            while(n != 0){
                mod = n % 10;
                res = res + mod*mod;
                n = n / 10;
            }
            if(res == 1){
                return true;
            }else if(hashMap.containsKey(res)){
                return false;
            }else{
                hashMap.put(res,1);
                n = res;
                res = 0;
            }
        }

    }

    /**
     * 平方和
     * @param n
     * @return
     */
    public int sqrt(int n){

        int mod = 0;
        int res = 0;

        while(n != 0){
            mod = n % 10;
            res = res + mod*mod;
            n = n / 10;
        }

        return res;
    }

    public boolean isHappy2(int n) {



        int fast = n;
        int slow = n;
        do{

            slow = sqrt(slow);
            fast = sqrt(fast);
            fast = sqrt(fast);

        }while(slow != fast);

        return slow == 1;

    }
```