### 1.栈（通过）
第一种方法是使用栈来模拟二叉树的遍历，就是如果此时栈中的前两层都是null（"#"），那就将这颗子树弹出去，过程中要判断这棵子树的根节点是否为空，为空直接返回false，如果不为空将这棵树弹出去之后用一个"#"代替，这样一遍遍历下来栈中保留的就应该只有一个"#",对其进行判断，满足返回true，否则返回false
```java
class Solution {
    public boolean isValidSerialization(String preorder) {
        //还可以使用栈来模拟这个二叉树遍历的过程
        int n=preorder.length();
        if(n==0) return true;
        
        String[]arr=preorder.split(",");
        Stack<String> sk=new Stack<String>();
        
        for(int i=0;i<arr.length;i++){                         
            sk.push(arr[i]);
            while(sk.size()>=3&&sk.get(sk.size()-1).equals("#")&&sk.get(sk.size()-2).equals("#")) {
            	sk.pop();
            	sk.pop();
            	///如果根节点为空，返回false
            	if(sk.peek().equals("#")) return false;
            	sk.pop();
            	
            	sk.push("#");
            }

        }
        
        return sk.size()==1&&sk.peek().equals("#");
    }
}
```
### 2.找规律（通过）
我们知道二叉树有一个性质就是整棵树叶子节点的个数比内部节点的个数大1，当然在遍历的过程中，叶子节点的个数一定是小于等于内部节点的个数的，如果不满足这个条件，证明有根节点为空，直接返回false，遍历完成后，只需要验证一下上面说的性质就可以了
```java
class Solution {
    public boolean isValidSerialization(String preorder) {
        int n=preorder.length();
        if(n==0) return true;
        
        int n0=0; int n2=0;
        String[]arr=preorder.split(",");
        
        for(int i=0;i<arr.length;i ++){
            if(arr[i].equals("#")) n0++;
            else n2++;
            
            if(i!=arr.length-1&&n0>n2) return false;
        }
        
        return n0==n2+1;
    }
}

```