常规思路：使用hashMap存储实际数字和猜数字中对应数字0-9的个数。
由于只存在数字0-9，因此可以直接使用bucket[10]代替hashMap.
其他写法都是使用两个bucket数组来分别计算实际值和猜测值中0-9的个数，取较小值。
但实际上用一个bucket数组就够了。
假设实际值bucket[i] = m ,猜测值 bucket[i] = n, 两个桶就是min(m,n);
但是使用一个bucket[i] = m-n, 最后只需要计算bucket中正值的和sum.用总长度length减去sum就是猜对数字总数了。
cow = length - sum - bull 

```
public String getHint(String secret, String guess) {
        int[] bucket = new int[10];
        int bull = 0;
        int cow = 0;
        for(int i=0;i<secret.length();i++){
            if(secret.charAt(i)== guess.charAt(i)){
                bull++;
                continue;
            }
            bucket[secret.charAt(i) - '0'] += 1;
            bucket[guess.charAt(i) - '0'] -= 1;

        }
        //计算bucket中正值的个数
        for(int i=0;i<10;i++){
            if(bucket[i] > 0)
                cow+= bucket[i];
        }
        
        cow = secret.length() - cow - bull;
        String res = bull + "A" + cow + "B";
        return res;
    }
```


