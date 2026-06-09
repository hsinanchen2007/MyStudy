1.   使用栈来保存运算符号，左右括号，数字
2.   去掉空格
3.   符号中间的是数字
4.   遇到）符号计算（之前的数。
5.   处理原先存在连续数字

```
private  static List<String> mathMap=new ArrayList<>();

    static {
        mathMap.add("+");
        mathMap.add("-");
    }

    public static int calculate(String s) {
        //1 使用栈
        Stack<String> stack=new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c=s.charAt(i);
            //2 去空格
            if(c==' '){
//                System.out.println("去掉"+i+"位的空格");
            }else {
                    if(c==')'){// 4 遇到）符号计算（之前的数。
                        //使用另一个运算栈来计算并更换顺序
                        Stack<String> mathStack=new Stack<>();
                        String x=stack.pop();
                        while (!"(".equals(x)){
                            mathStack.push(x);
                            if(!stack.isEmpty()){
                                x=stack.pop();
                            }
                        }
                        //将运算结果压入栈
                        stack.push(getMathstackSum(mathStack).toString());

                    }else{
                        // 5 处理原先存在连续数字,判断长度后直接压入。
                        if(c>='0'&&c<='9'){
                            String s2="";
                            int end=i;
                            //寻找到结束点
                            for (int j = i; j <s.length() ; j++) {
                                char c1=s.charAt(j);
                                if((c1>='0'&&c1<='9')){ //是数字
                                    end++;
                                }else {
                                    break;
                                }
                            }
                            s2=s.substring(i,end);
//                            System.out.println("s2 "+s2);
                            stack.push(s2);
                            i+=end-i-1;
                        }else { //压入符号
                            stack.push(c+"");
                        }

                    }
            }

            //当到达最后一位数，计算之前的(从左到右依次计算)。
            if(i==s.length()-1){
                //使用另一个运算栈来计算并更换顺序
                Stack<String> mathStack=new Stack<>();
                while (!stack.isEmpty()){
                    mathStack.push(stack.pop());
                }

                return getMathstackSum(mathStack);
            }
        }

        return 0;
    }

    //运算栈，从左到右开始计算，返回计算结果
    public static  Integer getMathstackSum(Stack<String> mathStack){
        Integer sum=null,num1;
        while (!mathStack.isEmpty()){
            String x2=mathStack.pop();
            if(null==sum){
                sum=Integer.parseInt(x2);
            }else if(mathMap.contains(x2)){
                num1=Integer.parseInt(mathStack.pop());
                if("+".equals(x2)){
                    sum+=num1;
                }else if("-".equals(x2)){
                    sum-=num1;
                }
            }
        }
        return sum;
    }

```

