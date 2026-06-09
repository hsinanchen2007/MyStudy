在遍历数组的过程中，计算每个数字的频率映射val2Freq,再统计频率的频率。对于满足条>件的前缀，此刻的‘频率的频率’有以下几种可能：
1. 所有元素频率相等，除了其中一个元素多了一个：freq2Freq大小为2，且他们的key的差为1，大的那个值为1
2. 一个值出现一次，其他值出现一次:freq2Freq大小为1，val为1。
3. 一个值出现一次，其他值出现相同次数(>1次）：freq2Freq大小为2，且其中一个key为1且值为1.
4. 一个值出现一次，其他值出现0次：freq2Freq大小为1，key为1且值为1.

遍历过程中记录满足条件的前缀出现时对应的最大i即可。
时间复杂度：O(N),空间复杂度O(N)用map来记录频率。

```
   public int maxEqualFreq(int[] nums) {
        Map<Integer,Integer> val2Freq=new HashMap<>();
        Map<Integer,Integer> frq2ffrq=new HashMap<>();
        int res=0;
        for (int i = 0; i < nums.length; i++) {
            int val=nums[i];
           int newFrq= addMap(val2Freq,val,1);

            //从原有map中移除
            int oldFrq=newFrq-1;
            if(oldFrq!=0)
                addMap(frq2ffrq,oldFrq,-1);
            //
            addMap(frq2ffrq,newFrq,1);

            if(frq2ffrq.size()==2){
                ArrayList<Integer> vals= new ArrayList<>(frq2ffrq.keySet());
                int a=vals.get(0);
                int b=vals.get(1);
                if(a>b){
                    int tmp=a;
                    a=b;
                    b=tmp;
                }
                //a<b
                if(a==1&&frq2ffrq.get(a)==1){
                    res=i;
                }else if(b-a==1&&frq2ffrq.get(b)==1){
                    res=i;
                }
            }else if(frq2ffrq.size()==1){
                int key=new ArrayList<>(frq2ffrq.keySet()).get(0);
                if(key==1||frq2ffrq.get(key)==1) {
                    res = i;
                }
            }
        }
        return res+1;
    }

    private int addMap(Map<Integer, Integer> val2Freq, int key, int val) {
        if(val2Freq.containsKey(key)){
            val=val2Freq.get(key)+val;
            val2Freq.put(key,val);
        }else {
            val2Freq.put(key,val);
        }
        if(val==0){
            val2Freq.remove(key);
        }
        return val;
    }
```
