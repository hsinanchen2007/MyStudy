# 解法一
`执行用时 :
108 ms
, 在所有 java 提交中击败了
80.33%
的用户
内存消耗 :
40.4 MB
, 在所有 java 提交中击败了
90.00%
的用户`
```
class ExamRoom {
    TreeMap<Integer,Integer> treeMap = new TreeMap<>();
    int n = 0;

    public ExamRoom(int N) {
        n = N;
    }

    public int seat() {
        int pre =-1;
        int max =0;
        int index =0;
        int next = 0;
        if(treeMap.isEmpty()){
            treeMap.put(0,null);
            return 0;
        }
        Iterator<Integer> iterator = treeMap.keySet().iterator();
        while(iterator.hasNext()){
            next = iterator.next();
            if(pre==-1){
                max = next;
                index = 0;
            }else{
                if((next-pre)/2 >max){
                    max = (next-pre)/2;
                    index = (next+pre)/2;
                }
            }
            pre = next;
        }
        if(next != n-1){
            if(n-1 -pre > max){
                index = n-1;
            }
        }
        treeMap.put(index,null);
        return index;

    }

    public void leave(int p) {
       treeMap.remove(p);
    }
}
```

# 解法二
使用数组，内存超过限制...
```
class ExamRoom {
    int[] arr = null;

    public ExamRoom(int N) {
        arr = new int[N];      
    }
    
    public int seat() {
        int pre =-1;
        int max =0,index=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0){
                if(i==arr.length-1){
                    if(pre==-1){
                        arr[0]=1;
                        return 0;
                    }
                    if(i-pre > max){
                        arr[i]=1;
                        return i;
                    }
                }
            }else{
                if(pre==-1){
                    max = i;                    
                    index =0;
                }else{
                    if((i+pre)/2-pre >max){
                        max = (i+pre)/2-pre;
                        index = (i+pre)/2;
                    }
                }
                pre = i;
            }

        }
        arr[index]=1;
        return index;
    }
    
    public void leave(int p) {
        arr[p] =0;
    }
}
```
