1. 方法一：回溯算法。
回溯算法适合枚举所有组合。并且回溯算法是**深度优先**的，即先遍历出一个组合，再尝试遍历第二个组合。速度较快。

回溯算法的难点在于1、如何把各个阶段的元素组合起来；2、如何存放各种情况。这题是String所以直接String+String就可以了。然后根据深度优先，搜索到边界情况时，用一个List来存放便可。
这里的代码是参考[@LeetCode](/u/leetcode/)官方发布的题解。

```
class Solution {
    Map<String,String> phone = new HashMap<String,String>(){{
        put("2","abc");
        put("3","def");
        put("4","ghi");
        put("5","jkl");
        put("6","mno");
        put("7","pqrs");
        put("8","tuv");
        put("9","wxyz");
    }};
    
    List<String> ans = new ArrayList<>();
    
    //回溯算法一般使用继承于Collection<E>接口的数据类型来存放不同组合的结果，然后使用for循环一次递归调用特定情况，从而遍历所有情况
    public void backTrace(String combination, String number){
        if(number.length()==0){
            ans.add(combination);
        }else{
            String letters = phone.get(number.substring(0,1));
            String letter;
            for(int i=0;i<letters.length();i++){
                letter = letters.substring(i,i+1);
                backTrace(combination+letter,number.substring(1));
            }
        }
    }
    public List<String> letterCombinations(String digits) {
        // for(int i=0;i<digits.length();i++){
        //     backTrace("",substring(i,i+1));
        // }
        if(digits.length()==0||digits==null) return ans;
        backTrace("",digits);
        return ans;
}
```



1. 方法二：新建树类

以为需要自己搭建树类，比较复杂，且运行时间也较慢。

自己新建树类的话，其实是**广度优先**，用递归函数来实现所有情况的遍历

```
public class letterCombinations {
	
	public static void main(String[] args) {
		letterCombinations mainObject = new letterCombinations();
		mainObject.soluiton1("23");
	}
	
	//新建树类来解决，比较复杂，运行时间也较慢
	public List<String> soluiton1(String digits) {
        String[][] dictionary = {{"a","b","c"},
        		{"d","e","f"},{"g","h","i"},
        		{"j","k","l"},{"m","n","o"},
        		{"p","q","r","s"},{"t","u","v"},
        		{"w","x","y","z"},{""}};

        int len = digits.length();
        int tempLoc = 0;
        letterTree LT = new letterTree(dictionary, 8, 0);
        for(int i=0;i<len;i++){
            tempLoc = Integer.parseInt(digits.substring(i,i+1))-2;
            LT.insert(dictionary,tempLoc);
        }
        List<String> ans = LT.combination();

        return ans;
    }

    class letterTree{

        int layer;
        String letter;
        boolean isEnd;
        letterTree LL;
        letterTree ML;
        letterTree MR;
        letterTree RR;


        public letterTree(String[][] dictionary, int num, int ind){
            this.layer = num;
            this.letter = dictionary[num][ind];
            this.isEnd = true;
        }

        public void insert(String[][] dictionary, int num){
            if(this.isEnd) {
            	this.LL = new letterTree(dictionary, num, 0);
            	this.ML = new letterTree(dictionary, num, 1);
            	this.MR = new letterTree(dictionary, num, 2);
            	if(dictionary[num].length==3){
            		this.RR = null;
            	}else if(dictionary[num].length==4){
            		this.RR = new letterTree(dictionary, num, 3);
            	}
            }else {
            	this.LL.insert(dictionary, num);
            	this.ML.insert(dictionary, num);
            	this.MR.insert(dictionary, num);
               	if(this.RR!=null){
            		this.RR.insert(dictionary, num);
            	}
            }
            this.isEnd = false;
        }

        public List<String> combination(){
            if(this.isEnd){
                List<String> temp = Arrays.asList(this.letter);
                return temp;
            }else{
                List<String> tempList = new ArrayList<>();
                for(String str:this.LL.combination()) {
                	tempList.addAll(Arrays.asList(this.letter+str));
                }
                for(String str:this.ML.combination()) {
                	tempList.addAll(Arrays.asList(this.letter+str));
                }
                for(String str:this.MR.combination()) {
                	tempList.addAll(Arrays.asList(this.letter+str));
                }
                if(this.RR!=null) {
                	for(String str:this.RR.combination()) {
                    	tempList.addAll(Arrays.asList(this.letter+str));
                    }
                }
                return tempList;
            }
        }
    } 
}

```

