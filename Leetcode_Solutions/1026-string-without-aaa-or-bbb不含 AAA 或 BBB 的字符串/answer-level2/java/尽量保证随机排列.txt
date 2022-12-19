感觉代码还可以优化，希望大佬来指点，带我出坑。
```java
class Solution {
    public String strWithout3a3b(int A, int B) {
     
        //如：输入A=3，B=3
        //1.设置一个随机flag，0表示‘a’，1表示‘b’
        //2.开始时，判断A和B的个数，多的先排列（个数多2个或2个以上的）
        //3.后面排列的字符，需要判断A和B的剩余数，依然个数多2个或2个以上的先排列
        //4.识别当前输出的结果String末尾是否是"aa"或"bb"，如果是的话，立即换另一种字符排列。（index == i-2 ？需要换:不需要换）

        //注意：之所以用2来判断两数的差，因为abbb，或aaab，这种相减得出。如果if里为true，那就先排多的，为后边减少一次出现连续三个字符的可能
        
        int start = new Random().nextInt(2);
        if(B-A >= 2){   
        	start = 1;
        }
        if(A-B >= 2){
        	start = 0;
        }
        StringBuilder result = new StringBuilder();
        int count = A+B;
        if(start == 0){
        	//‘a’打头
        	result.append('a');
            A-=1;
        }else{
        	//‘b’打头
        	result.append('b');
            B-=1;
        }
        for(int i=1; i<count; i++){
            int flag = new Random().nextInt(2);
            if(B-A >= 2){
            	flag = 1;
            }
            if(A-B >= 2){
            	flag = 0;
            }
            if(flag == 0){
            	int index = result.toString().lastIndexOf("aa");
            	if(A>0 && (index < 0 || index != i-2)){
            		result.append('a');
                    A--;
            	}else{
            		result.append('b');
                    B--;
            	}
            }else if(flag == 1){
            	int index = result.toString().lastIndexOf("bb");
            	if(B>0 && (index < 0 || index != i-2)){
            		result.append('b');
                    B--;
            	}else{
            		result.append('a');
                    A--;
            	}
            }
        }
        
        return result.toString();
        
    }
}