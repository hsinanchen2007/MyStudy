>根据题意所给条件，当所给的两个 ```word```相同时，计算的则是相邻 ```word```的距离的最小值，则只需要增加一个判断，当两个 ```word``` 相同的时候，计算出所有 ```word``` 的 ```index``` , 再进行一次遍历，计算出间隔最小值即可，当然，也可以仅记录上一个 ```word``` 的 ```index``` 的位置，计算与当前 ```index```的差值，并在记录下标时就更新 ```minDist``` 的值，可以节省 $O(N)$ 的空间开销和一次循环，不过懒得写了哈哈。 
```
public int shortestWordDistance(String[] words, String word1, String word2) {
        int minDist = Integer.MAX_VALUE;
        int curDist;
        if(word1.equals(word2)){
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < words.length; i++) {
                if (words[i].equals(word1)){
                    list.add(i);
                }
            }
            for (int i = 1; i < list.size(); i++) {
                curDist = Math.abs(list.get(i)- list.get(i-1));
                minDist = minDist<curDist?minDist:curDist;
            }
            return minDist;
        }
        
        int index1=-1;
        int index2=-1;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1)){
                index1=i;
            }
            if (words[i].equals(word2)){
                index2=i;
            }
            if(index1!=-1 && index2!=-1){
                curDist = Math.abs(index1-index2);
                minDist = minDist<curDist?minDist:curDist;
            }
        }
        return minDist;
        
    }
```
