看了不少题解，没看到什么清楚易懂的，自己想了一个。
思路就是先遍历一遍secret，将secret和guess中的公牛字符删去，同时将非公牛字符加入到list中，
遍历无公牛值的guess，如果其中元素存在于list中，就将奶牛值+1，并在list中删掉该元素。
```
class Solution {
    public String getHint(String secret, String guess) {
        // int len=secret.length();
        // 用列表来存储secret中的值（具体而言是secret中的非公牛值）
        List<Character> list=new LinkedList<>();
        // countA是公牛值，countB是奶牛值
        int countA=0;
        int countB=0;
        // 将guess转为字符串数组
        char[] guessArray=guess.toCharArray();
        for(int i=0;i<secret.length();i++){
            if(secret.charAt(i)==guess.charAt(i)){
                countA++;
                // 将guess中公牛值用一个list中根本不存在的值(#)代替，这样就相当于把它给删掉了
                guessArray[i]='#';
            }
            else{
                // 将secret中非公牛值加入到列表中
                list.add(secret.charAt(i));
            }        
        }
        // 注意：经过上述循环，计算出了公牛值，同时列表中只包含secret中的非公牛字符
        // 下面要遍历guessArray，如果guessArray中的元素出现在列表中，奶牛值+1
        for(int i=0;i<guessArray.length;i++){
            if(list.contains(guessArray[i])){
                countB++;
                // 删掉该元素，以防后续遍历中还有和它相等的元素导致奶牛值重复+1
                list.remove((Object)guessArray[i]);
            }
        }
        return countA+"A"+countB+"B";
    }
}
```
