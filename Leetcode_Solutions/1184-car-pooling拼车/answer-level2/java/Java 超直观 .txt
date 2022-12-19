```java []
public boolean carPooling(int[][] trips, int capacity) {
        // 由于至多有1000个站点，可以创建两个数组分别记录上下车情况
        int[] in = new int[1001];   //站点上车情况统计
        int[] out = new int[1001];  //站点下车情况统计
        for(int[] trip:trips){
            in[trip[1]] += trip[0]; //我提交了两次，第一次出错在这里，我原来的代码是 in[trip[1]] = trip[0]
            out[trip[2]] += trip[0];  //out[trip[2]] = trip[0], 相信你们也一眼就能看出来为什么错了
        }
        // 经过上面的统计就不需要再考虑上下车次序问题了，仅需要进行从头到尾的遍历，并判断是否超载就可以了
        int cust = 0;
        for(int i = 1; i <= 1000; ++i){
            cust -= out[i];
            cust += in[i];
            if(cust < 0) return false;
            if(cust > capacity) return false;
        }
        return true;
    }
```
```
