```java
class Solution {

    //返回最大公约数
    public int gcd(int a, int b){
        while(b != 0){
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    public boolean hasGroupsSizeX(int[] deck) {
        int bucket[] = new int[10001];
        for(int c: deck)
            bucket[c]++;
        
        int bucket2[] = new int[10001];
        Arrays.sort(bucket);
        for(int i = 0, j = 0; i < bucket.length; i++){
            if(bucket[i] != 0){
                bucket2[j++] = bucket[i];
            }
        }

        if(bucket2[0] < 2) return false;
        for(int i = 1; i < bucket2.length; i++){
            if(bucket2[i] != 0){
                if(gcd(gcd(bucket2[1], bucket2[0]), bucket2[i]) < 2)
                    return false;
            }else
                break;
        }
        return true;
    }

```
