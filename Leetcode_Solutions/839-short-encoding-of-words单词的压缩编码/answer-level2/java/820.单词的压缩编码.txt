### 解题思路
此处撰写解题思路
1. 遇到单词问题，可以考虑数组，即char'i'-char'a'
2. 这道题目给了提示每个字母都是小写字母，并且长度都小于7
3. 刚开始我用的26个大小的数组，但是单词考虑的不仅仅是数量上面的问题，更是顺序的问题
4. 回过头来看题，发现题目要求单词的长度不大于7，所以定义一个长度为7的数组，并且从后向前的顺序将每个单词的字符填进长度为7的数组里
5. 并比较在他之前的单词（我重写了sort方法，使得给定单词数组按从大大小排序）
### 代码

```java
class Solution {
    public static int minimumLengthEncoding(String[] words) {
        // if(words.length==1){
        //     return wo.length;
        // }
        int lengthW=words.length;
        int sumCount=0;
        // System.out.println(lengthW);
        // System.out.println(words[0].length());
        Arrays.sort(words,new Comparator<String>(){
            public int compare(String a,String b){
                return b.length()-a.length();
            }
        });
        int lengthMax=words[0].length();
        int arr[][]=new int[lengthW][7];
        boolean flag=true;
        int x=6;
        for(int i=0;i<lengthW;i++){
            String word=words[i];
            for(int j=word.length()-1,c=6;j>=0&&c>=0;j--,c--){
                arr[i][c]=word.charAt(j);
            }
            if(i==0){
                sumCount=sumCount+words[i].length()+1;
//                System.out.println(sumCount);
            }else if(i>0){
                sumCount=sumCount+words[i].length()+1;
                if(words[i].length()<=lengthMax){
                    for(int first=0;first<i;first++){
//                        if(words[i].length()==words[first].length()){
//                            System.out.println(arr[first].length);
//                            System.out.println(arr[i].length);
//                            System.out.println("======");
//                            break;
//                        }
                        for(x=6;x>=7-word.length();x--){
                            if(arr[i][x]!=arr[first][x]){
                                break;
                            }
                        }
                        if(x==7-word.length()-1){
                            sumCount=sumCount-words[i].length()-1;
                            break;
                        }
                    }


                }
            }
        }
        return sumCount;
    }

    }
```