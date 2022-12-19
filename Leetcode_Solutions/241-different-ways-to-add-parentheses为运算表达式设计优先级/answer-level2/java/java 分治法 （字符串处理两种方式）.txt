# 分治
分解成容易解决的子问题：也就是按运算符分成左右两部分，分别计算后，利用分隔符，合并

关于分治的更详细描述，请看：

tip:https://blog.csdn.net/qq_21515253/article/details/96216125

# **策略**

1、不处理字符串，以string形式进行partition

2、分割字符串（split），分离出所有参与运算的数字（数量为n）和符号(数量为n-1)

注：**(1)分隔符数量为string中符号数

    (2)策略一效率优于策略二**


# 策略一：
```java []
class Solution {
    
    public List<Integer> diffWaysToCompute(String input) {
        return partition(input);
    }
    
    public List<Integer> partition(String input) {
        List<Integer> result = new ArrayList<>();
        if (!input.contains("+") && !input.contains("-") && !input.contains("*")) {
            result.add(Integer.valueOf(input));
            return result;
        }
        for(int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-' || input.charAt(i) == '*') {
                for(Integer left : partition(input.substring(0, i))) {
                    for (Integer right : partition(input.substring(i + 1))) {
                        if (input.charAt(i) == '+') {
                            result.add(left + right);
                        } else if (input.charAt(i) == '-') {
                            result.add(left - right);
                        } else if (input.charAt(i) == '*') {
                            result.add(left * right);
                        }
                    }
                }
            }
        }
        return result;
    }
}
```

# 策略二
```java []
class Solution {
    ArrayList<Character> op = new ArrayList<>();
    String[] nums;
    
    public void split(String input) {
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-' || input.charAt(i) == '*') {
                op.add(input.charAt(i));
            }
        }
        nums = input.split("[\\+\\-\\*]");
        //System.out.println(nums.length);
        //System.out.println(op.size());
    }
    
    public List<Integer> diffWaysToCompute(String input) {
        split(input);
        return paitition(0, nums.length - 1);
    }
    
    public List<Integer> paitition(int start, int end) {
        List<Integer> result = new ArrayList<>();
        if (start == end) {
            result.add(Integer.valueOf(nums[start]));
            return result;
        }
        
        for (int i = start; i < end; i++) {
            for (Integer left : paitition(start, i)) {
                for (Integer right : paitition(i + 1, end)) {
                    //System.out.println(left);
                    //System.out.println(right);
                    if (op.get(i) == '+') {
                        result.add(left + right);
                    } else if (op.get(i) == '-') {
                        result.add(left - right);
                    } else if (op.get(i) == '*') {
                        result.add(left * right);
                    }
                }
            }
        }
       // System.out.println("退出递归");
        return result;
    }
}
```



