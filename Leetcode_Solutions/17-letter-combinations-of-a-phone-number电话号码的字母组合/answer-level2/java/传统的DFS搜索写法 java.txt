先上代码
```
class Solution {
    public List<String> letterCombinations(String digits) {
        char[][] table = {{'2','a','b','c','0'},
                          {'3','d','e','f','0'},
                          {'4','g','h','i','0'},
                          {'5','j','k','l','0'},
                          {'6','m','n','o','0'},
                          {'7','p','q','r','s'},
                          {'8','t','u','v','0'},
                          {'9','w','x','y','z'}};
        List<String> result = new ArrayList<>();
        if (digits.equals("")){
            return result;
        }
        dfs(0,digits,table,"",result);
        return result;
    }
    public static void dfs(int step,String digits,char[][] table,String s,List<String> result){
        if (step==digits.length()){
            String t = s;
            result.add(t);
            return;
        }
        int t = 0;
        for (int i=0;i<8;i++) {
            if(digits.charAt(step)==table[i][0]) {
                t = i;
                break;
            }
        }
        for (int i=1;i<=4;i++){
            if (table[t][i]!='0') {
                s = s + table[t][i];
                dfs(step + 1, digits, table, s,result);
                s = s.substring(0, step);
            }
        }
    }
}
```
首先是在函数里定义了一个二维数组存储对应的关系，然后就是标准的深搜代码了。开头就是if判断返回条件，当搜到最后一个字母的后面时，就记录下当前的字符串并将它添加到list里面，然后return回去。中间的for循环是判断字符串的下标为step的字符对应的数字是多少，这样可以想到它后面跟上的对应的字母是哪些。这里要说明一下，我申请的是8x5的数组，除了第一个是对应的数字以外，后面凡是有空一格的，都用‘0’填进去，这样在遍历的时候比较容易判断。然后搜索的主体就是对每个数字对应的那个一维数组进行遍历，而回溯的操作我用subString函数来完成。这样就是标准的教科书式的搜索架构吧，可能我传的参数太多了，有点麻烦。s是用来记录组合的串的，result是要返回的list。其他的不懂可以问我，大二学生的代码，凑活看一哈吧。