```java
一开始考虑的是先找到最大字母还有每个字母的位置存进list，当list.size()!=1的时候对每个位置开始往后找，然后不停的把小的从list里删掉，后来转换思路从前向后依次对比，但是需要注意重复直问题，测试用例中有一个无限长的string全是'a' ->"aaaaaaaaaaaaaaaaaa........." 如果不去重会超时
class Solution {
    public String lastSubstring(String s) {
        char[] array = s.toCharArray();
        int k = 0;
        for(int i=1; i<s.length(); i++){
            if(array[k] < array[i]){
                k = i;
            }else if(array[k] == array[i] && array[i] != array[i - 1]){
                for(int j=0; i+j<s.length(); j++){
                    if(array[k+j] < array[i+j]){
                        k = i;
                        break;
                    }else if(array[k+j] > array[i+j]){
                        break;
                    }
                }
            }
        }
        return s.substring(k);
    }
}
```