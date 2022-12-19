用了3个HashMap，由于每个String的最长长度只有16，可以根据String的长度进行遍历，找到每个word的子word，然后使用动态规划的思想，找到最大长度，动态规划状态转移方程为：
```
maxLength = Math.max(maxLength, maxSonMap.get(tmpSon));
```

执行用时 :
60 ms, 在所有 Java 提交中击败了85.25%的用户
内存消耗 :46.1 MB, 在所有 Java 提交中击败了100.00%的用


看了最优解，

```
HashMap<String, List<String>> sonMap = new HashMap<>();
HashMap<String, Integer> maxSonMap = new HashMap<>();
```
这两个映射全部用List实现，用下标来索引，这样比用String来索引快很多。看来着了HashMap的迷

```
class Solution {
    public int longestStrChain(String[] words) {
        HashMap<Integer, List<String>> lengthMap = new HashMap<>();
        HashMap<String, List<String>> sonMap = new HashMap<>();
        HashMap<String, Integer> maxSonMap = new HashMap<>();
        
        for(int i=1; i<=16; i++){
            lengthMap.put(i, new LinkedList<>());
        }
        
        for(String tmp: words){
            lengthMap.get(tmp.length()).add(tmp);
            sonMap.put(tmp, new LinkedList<>());
        }
        
        for(int i=1; i<16; i++){
            for(String tmpParent: lengthMap.get(i)){
                for(String tmpSon: lengthMap.get(i+1)){
                    if(this.isSon(tmpParent, tmpSon)){
                        sonMap.get(tmpParent).add(tmpSon);
                    }
                }
            }
        }
        int maxlian = 1;
        for(int i=16; i>=1; i--){
            for(String tmp: lengthMap.get(i)){
                List<String> tmpList = sonMap.get(tmp);
                if(tmpList.size() == 0){
                    maxSonMap.put(tmp, 1);
                }else{
                    int maxLength = Integer.MIN_VALUE;
                    for(String tmpSon: tmpList){
                        maxLength = Math.max(maxLength, maxSonMap.get(tmpSon));
                    }
                    maxlian = Math.max(maxlian, maxLength + 1);
                    maxSonMap.put(tmp, maxLength + 1);
                }
            }
        }
        
        return maxlian;
        
    }
    
    private boolean isSon(String parent, String son){
        int i=0, j=0;
        boolean bian = true;
        while(i<parent.length() && j<son.length()){
            if(parent.charAt(i) == son.charAt(j)){
                i++;
                j++;
            }else{
                if(bian){
                    bian = false;
                    j++;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
}

```