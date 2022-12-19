### 解题思路

原數組已經過排序,故由左向右檢查每個元素. 

當每次檢視元素時, 先考慮是否可讓已存在的列作延長, 若可則延長列. 
所以需要有一個 Map 來記錄 列的最後一個元素, 和整個列的對應清單(List, 可能有數個列皆以同元素結束).

當無法作延長列的操作時, 則直接向右檢視是否可以組成新列. 舉例如下:
已存在列有: `[1,2,3],[2,3,4]` 未處理數組有: `[6,7,7,8,8,...]`
當我們檢視未處理數組中第一個元素其值為 `6` 發現無法讓現有已存在的列作延長, 所以我們直接檢查是否存在 `[6,7,8]` 列, 若存在, 則直接將 `6,7,8` 三個元素直接由 '未處理數組' 中搶走, 型成下列狀態:
已存在列有: `[1,2,3],[2,3,4],[6,7,8]` 未處理數組有: `[7,8,...]`
之後再依序檢查 未處理數組 中的第一個元素。


### 代码

```java
class Solution {
    /* 由未處理數組中, 試先搶三連續數組成列, 若失則則回傳空值 */
    List<Integer> getMinLst(List<Integer> numAL){
        if(numAL.size()<3) return null;
        int ky=numAL.get(0);
        int ix2=Collections.binarySearch(numAL,ky+1);
        if(ix2<0) return null;
        int ix3=Collections.binarySearch(numAL,ky+2);
        if(ix3<0) return null;
        List<Integer> ansAL=new ArrayList<>();
        ansAL.add(0,numAL.remove(ix3));
        ansAL.add(0,numAL.remove(ix2));
        ansAL.add(0,numAL.remove(0));
        return ansAL;
    }
    public boolean isPossible(int[] nums) {
        List<Integer> numAL=Arrays.stream(nums).boxed().collect(Collectors.toList());//int[]->List
        Map<Integer,List<List<Integer>>> endHm=new HashMap<>();//記錄列尾元素 所對應的 列清單
        while(!numAL.isEmpty()){// 若還有未處理數
            int ky=numAL.get(0);// 檢視第一個未處理數
            if(endHm.containsKey(ky-1)&&endHm.get(ky-1).size()>0){//若 ky 值可以接續已有的列
                List<Integer> tmpAL=endHm.get(ky-1).remove(0);//將該列由 Map 移出
                tmpAL.add(numAL.remove(0));//將 ky 由 未處理數組中移出, 加到列中.
                // 該列的列尾元素已變, 需更新到 Map 中
                if(!endHm.containsKey(ky)) endHm.put(ky,new ArrayList<>());
                endHm.get(ky).add(tmpAL);
            }else{// 若 ky 無法接續已有的列
                List<Integer> tmpAL = getMinLst(numAL);//試搶三元素組成列
                if(tmpAL==null) return false;//組列失敗, 其解為否, 回傳之
                // 該列的需更新到 Map 中
                int lastKy=tmpAL.get(tmpAL.size()-1);
                if(!endHm.containsKey(lastKy)) endHm.put(lastKy,new ArrayList<>());
                endHm.get(lastKy).add(tmpAL);
            }
        }
        return true;//所有數皆找到列, 其解為真
    }
}
```