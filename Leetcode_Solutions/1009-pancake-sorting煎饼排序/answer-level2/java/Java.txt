思路还是那个思路
找到当前未排序的最大的值交换到开头，然后再交换到未排序值的结尾

本解法主要是使用了indexs数组记录了数字下标的变化，每一次翻转都更新下标数组
```
执行用时 :
3 ms, 在所有 Java 提交中击败了97.34%的用户
内存消耗 :
36.8 MB, 在所有 Java 提交中击败了77.69%的用户
```

```
 public List<Integer> pancakeSort(int[] A) {
        List<Integer> res = new ArrayList<>();
        int len = A.length;
        
        int[] indexs = new int[len+1];
        
        for(int i=0 ; i<len ; i++){
            indexs[A[i]] = i;
        }
        
      
        int cur = A.length;
        
        while(cur>0){
            int index = indexs[cur];
            if(index==cur-1){
                --cur;
                continue;
            }
            if(index!=0){ //将最大值翻转到最前方
                res.add(index+1);
                update(indexs,index);
            } 
            //将最大值翻转到未排序的最后           
            res.add(cur);
            update(indexs,cur-1);
            --cur;
        }
        
        return res;
    }
    

    //更新下标数组
    void update(int[] indexs,int k){
 
        for(int i=0 ; i<indexs.length ; i++){
            if(indexs[i]<=k){
                indexs[i] = k-indexs[i];
            }
        }
    }
```
