

### 代码

```java
class Solution {
    private String[] words;
    private String result;
    public  boolean isSolvable(String[] words, String result) {
        this.words = words;
        this.result = result;
        //保存所有不重复的字母
        Set<Character> set = new HashSet();
        //保存开头字母，确保其不能为零
        Set<Character> first = new HashSet();
        for(String word: words){
            //保存开头字母
            first.add(word.charAt(0));
            for(int i=0;i<word.length();i++){
                set.add(word.charAt(i));
            }
        }
        //保存开头字母
        first.add(result.charAt(0));
        for(int i=0;i<result.length();i++){
            set.add(result.charAt(i));
        }
        //转换为list，便于根据下标来遍历
        List<Character> list = new ArrayList(set);
        //如果不同字母的长度大于10，则不能保证每个字母对应一个数字，直接返回false
        if(list.size() > 10){
            return false;
        }
        //保存26个字母对应的数值
        int[] map = new int[26];
        //先初始化为零
        Arrays.fill(map,-1);

        //保存10个数字，哪些已经被使用过了
        boolean[] used = new boolean[10];
        return exhaustivity(list,first,map,used,0);
    }

    private boolean exhaustivity(List<Character> list,Set<Character> first,int[] map,boolean[] used,int index){
        //当搜索的字母都映射有值之后，做针对单词做累加比较
        if(index == list.size()){
            return sumIsSame(map);
        }
        char c = list.get(index);
        //全排列组合，穷举为字母赋值
        for(int i=0;i<10;i++){
            //特殊处理首字母，不能为零
            if((i==0&&first.contains(c)) || used[i]){
                continue;
            }
            map[c-'A'] = i;
            used[i] = true;
            boolean isSame = exhaustivity(list,first,map,used,index+1);
            if(isSame){
                return true;
            }
            //如果当前字母的赋值不匹配，需要针对当前字母做还原
            map[c-'A'] = -1;
            used[i] = false;
        }
        return false;
    }

    //按照已赋值的字母，针对单词做累计比较
    private boolean sumIsSame(int[] map) {
        int sum1 = 0,sum2=0;
        for(String word: words){
            int temp = 0;
            for(int i=0;i<word.length();i++){
                temp *= 10;
                temp += map[word.charAt(i) - 'A'];
            }
            sum1 += temp;
        }
        for(int i=0;i<result.length();i++){
            sum2 *= 10;
            sum2 += map[result.charAt(i) - 'A'];
        }
        return sum1 == sum2;
    }
}
```