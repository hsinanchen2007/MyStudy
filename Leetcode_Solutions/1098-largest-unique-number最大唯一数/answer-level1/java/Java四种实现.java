## 利用TreeMap统计次数并排序
8ms，时间复杂度O(NlogN)

```
    public int largestUniqueNumber(int[] A) {
        TreeMap<Integer,Integer> map=new TreeMap<>();
        for(int val:A){
            map.put(val,map.getOrDefault(val,0)+1);
        }
        while(!map.isEmpty()){
            int largest=map.lastKey();
            if(map.get(largest)==1){
                return largest;
            }
            map.remove(largest);
        }
        return -1;
    }
```

## 排序后从后往前找
2ms,O(NlogN)

```
 public int largestUniqueNumber(int[] A) {
        Arrays.sort(A);
        int n=A.length;
        int i=n-1;
        while(i>=0){
            //找到最大的值
            int max=A[i];
            i--;
            boolean hasSame=false;
            while(i>=0&&A[i]==max){
                hasSame=true;
                i--;
            }
            if(!hasSame){
                return max;
            }
        }
        return -1;
    }
```

## 排序+二分
先找到最后一个，二分搜索找到该值的第一个出现的位置，O(NlogN) 2ms

```
    public int largestUniqueNumber(int[] A) {
        Arrays.sort(A);
        int n=A.length;
        int i=n-1;
        while(i>=0){
            int max=A[i];
            int idx=firstPos(A,max,0,i-1);
            if(idx==-1){
                return max;
            }
            i=idx-1;
        }
        return -1;
    }

    private int firstPos(int[] A,int val,int start,int end){
        while(start<=end){
            int mid=((start+end)>>1);
            if(A[mid]==val){
                if(mid==0||A[mid-1]!=val){
                    return mid;
                }else{//可以向左走
                    end=mid-1;
                }
            }else if(A[mid]>val){
                end=mid-1;
            }else{//A[mid]<val
                start=mid+1;
            }
        }
        return -1;
    }
```

## 桶排序
根据题意，N<=2*10^3，取值M<=10^3 
O(N+M) 1ms，100%
```
    public int largestUniqueNumber(int[] A) {
        int[] frq=new int[1001];
        for(int val:A){
            frq[val]++;
        }
        for(int i=1000;i>=0;i--){
            if(frq[i]==1){
                return i;
            }
        }
        return -1;
    }
```

