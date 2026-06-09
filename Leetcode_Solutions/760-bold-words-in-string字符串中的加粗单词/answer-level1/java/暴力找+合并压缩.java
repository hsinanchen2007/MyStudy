### 解题思路
找到所有可以插入的位置；
然后进行合并，如果有重复或者重合；
输出。


### 代码

```java
class Solution {
    public String boldWords(String[] words, String S) {
        //error cases
        if(S==null || S.length()<1){
            return S;
        }else if(words==null || words.length<1){
            return S;
        }
        //corner cases

        /// # find
        LinkedHashSet<BoldPoint> boldPointSet = new LinkedHashSet<BoldPoint>();
        for(String w: words){
            int startSeachIndex = 0;
            int sIndex = S.indexOf(w, startSeachIndex);
            while(sIndex!=-1 && startSeachIndex<S.length()){
                int eIndex = sIndex+ w.length()-1;
                boldPointSet.add(new BoldPoint(sIndex, eIndex)); 

                if(w.length()>1 && w.charAt(0) == w.charAt(1)
                    && sIndex!=-1){
                    ///in case of ee vs eee
                    startSeachIndex++;
                }else{
                    startSeachIndex = eIndex+1;
                }
                sIndex = S.indexOf(w, startSeachIndex);
            }
        }
        if(boldPointSet.size()<1)
            return S;

        /// # combine & merge
        BoldPoint[] boldPointArray = new BoldPoint[boldPointSet.size()];
        Iterator<BoldPoint>  tempIterator = boldPointSet.iterator();
        int tempIndex = 0;
        while(tempIterator.hasNext()){
            boldPointArray[tempIndex++]=tempIterator.next();
        }
        Arrays.sort(boldPointArray, (a, b)->{
            return a.sIndex == b.sIndex ? a.eIndex-b.eIndex : a.sIndex - b.sIndex;
            });
        
        LinkedList<BoldPoint> filterPointArray = new LinkedList<BoldPoint>();
        BoldPoint preBoldPoint = boldPointArray[0];
        for(int i=1;i<boldPointArray.length; i++){
            if(!BoldPoint.isOverlap(preBoldPoint, boldPointArray[i])){
                filterPointArray.addLast(preBoldPoint);
                preBoldPoint = boldPointArray[i];
            }else{
                preBoldPoint = BoldPoint.merge(preBoldPoint, boldPointArray[i]);
            }
        }
        filterPointArray.addLast(preBoldPoint);

        LinkedList<Integer> bList = new LinkedList<>();
        LinkedList<Integer> _bList = new LinkedList<>();
        for(BoldPoint b : filterPointArray){
            bList.add(b.sIndex);
            _bList.add(b.eIndex);
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<S.length();i++){
            if(bList.size()>0&& bList.peekFirst() ==i){
                bList.pollFirst();
                sb.append("<b>");
            }
            sb.append(S.charAt(i));
            if(_bList.size()>0&& _bList.peekFirst() ==i){
                _bList.pollFirst();
                sb.append("</b>");
            }
        }
        return sb.toString();
    }
}
    class BoldPoint{
        public int sIndex;
        public int eIndex;
        public BoldPoint(int s, int e){ this.sIndex=s; this.eIndex = e;} 
        public BoldPoint(){} 

        public static boolean isOverlap(BoldPoint a, BoldPoint b){
            if( a.sIndex <= b.sIndex && b.sIndex<=a.eIndex
                || b.sIndex <= a.sIndex && a.sIndex<=b.eIndex
                || a.eIndex+1 == b.sIndex
                || b.eIndex+1 == a.sIndex)
                return true;
            return false;
        }

        public static BoldPoint merge(BoldPoint a, BoldPoint b){
            if(! isOverlap(a, b)){
                return null;
            }

            BoldPoint ret = new BoldPoint();
            ret.sIndex = Math.min(a.sIndex, b.sIndex);
            ret.eIndex = Math.max(a.eIndex, b.eIndex);
            return ret;
        }
    }
```