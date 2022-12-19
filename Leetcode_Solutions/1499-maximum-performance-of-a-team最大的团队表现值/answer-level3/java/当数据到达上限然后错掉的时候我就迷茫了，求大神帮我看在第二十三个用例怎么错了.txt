```
class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        quickSort(efficiency,speed,0,n-1);
        List<PriorityQueue<Integer>> res =new ArrayList<>();
        for(int i=0;i<n;i++){
            res.add(new PriorityQueue<>());
        }            
        long max=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                res.get(j).add(speed[i]*efficiency[j]);
                if(res.get(j).size()>k){
                    res.get(j).poll();
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            long sum=0;
            for(int c=0;c<res.get(i).size();){
                sum+=res.get(i).poll();
            }
            max=Math.max(sum,max);
        }
        return (int)(max % ((int)1e9 + 7));
        // return (int)max;
    }
    public static void quickSort(int a[],int b[],int l,int r){
     if(l>=r)
       return;
     //选择第一个数为key
     int i = l; int j = r; int key = a[l];
     int keyb=b[l]; 
        
     while(i<j){
         while(i<j && a[j]>=key)//从右向左找第一个小于key的值
             j--;
         if(i<j){
             a[i] = a[j];
             b[i] = b[j];
             i++;
         }
     while(i<j && a[i]<key)//从左向右找第一个大于key的值
             i++;
         if(i<j){
             a[j] = a[i];
             b[j] = b[i];
             j--;
         }
     }
     //i == j
     a[i] = key;
     b[i] = keyb;
     quickSort(a,b, l, i-1);//递归调用
     quickSort(a,b, i+1, r);//递归调用
 }
}
```

