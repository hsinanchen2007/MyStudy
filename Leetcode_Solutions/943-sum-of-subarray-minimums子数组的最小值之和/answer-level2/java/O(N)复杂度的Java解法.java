        //第一步：找出这个数字左边有几个，右边有几个，赋值为m、n；
        //第二部：计算以这个数字为最小值的情况有集中：(m+1)*(n+1);
        //第三步：遍历数组A的每一个元素，以其为最小数的次数乘其本身，再求和就是最后结果啦。

        //正常情况下，找出数组中每一个元素左边和右边各有几个连续的、比它小的数字的复杂度为n的二次方，
        //怎样可以优化算法复杂度呢。
        
        //是否可以维护一个栈，只存比当前栈顶元素更大的元素，在一个元素入栈之前要将所有比它小的数都弹出栈
        //那么，在这个元素入栈的时候，可以知道左边（连续）比他大的数有几个，出栈的时候会知道右边的数有几个。
        //这样，复杂度变为了O（N）.

        if(A==null||A.length==0)
            return 0;
        int len = A.length;
        
        int[] left=new int[len];
        int[] right = new int[len];
        Stack<Integer>stack = new Stack<>();
        for(int i=0;i<len;i++){
            while(!stack.isEmpty()&&A[i]<=A[stack.peek()]){
                int poppos = stack.pop();
                right[poppos] = i-poppos-1;
            }
            if(stack.isEmpty()){
                left[i] = i;
            }
            else{
                left[i] = i-stack.peek()-1;
            }
            stack.push(i);
        }
        while(!stack.isEmpty()){
            int pos = stack.pop();
            right[pos] = len-1-pos;
        }
        long res=0;
        for(int i=0;i<len;i++){
            res+=A[i]*(left[i]+1)*(right[i]+1);
        }
        return (int)(res% 1000000007);
    }