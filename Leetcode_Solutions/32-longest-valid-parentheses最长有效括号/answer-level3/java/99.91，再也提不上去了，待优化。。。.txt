下面是做题的经过，历经近十次优化，然鹅还是到不了100%

```
    /**
     * 1.时间上击败5%，空间90%。 离超时很近。
     * 
     * @Author kaikai 2019年9月24日 上午12:29:23
     * @param s
     * @return
     */
    public int longestValidParentheses(String s) {
        int longestLength = 0;
        int longestLengthTemp = 0;
        StringBuffer sb;
        for (int k = 0; k < s.length(); k++) {
            sb = new StringBuffer();
            longestLengthTemp = 0;
            for (int i = k; i < s.length(); i++) {
                if (s.charAt(i) == '(') {
                    sb.append(s.charAt(i));
                } else {
                    if (sb.length() <= 0) {
                        if (longestLength < longestLengthTemp)
                            longestLength = longestLengthTemp;
                        longestLengthTemp = 0;
                        continue;
                    }
                    sb.deleteCharAt(sb.length() - 1);
                    longestLengthTemp += 2;
                    // 每一次归0，都记下来
                    if (sb.length() == 0) {
                        if (longestLength < longestLengthTemp)
                            longestLength = longestLengthTemp;
                    }

                }
            }
            if (sb.length() == 0 && longestLength < longestLengthTemp)
                longestLength = longestLengthTemp;
        }

        return longestLength;
    }

    /**
     * 1. 时间上： 50.97， 空间上：68.22
     * 
     * @Author kaikai 2019年9月25日 下午11:18:55
     * @param s
     * @return
     */
    public int longestValidParentheses2(String s) {
        int longestLength = 0;
        int longestLengthTemp = 0;
        StringBuffer sb;

        sb = new StringBuffer();
        longestLengthTemp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                if (sb.length() == 0) {
                    if (longestLength < longestLengthTemp) {
                        longestLength = longestLengthTemp;
                    }
                }

                sb.append(s.charAt(i));
            } else {
                if (sb.length() <= 0) {
                    if (longestLength < longestLengthTemp) {
                        longestLength = longestLengthTemp;
                    }
                    longestLengthTemp = 0;
                    sb = new StringBuffer();
                    continue;
                }
                sb.deleteCharAt(sb.length() - 1);
                longestLengthTemp += 2;

            }
        }
        if (sb.length() == 0 && longestLength < longestLengthTemp)
            longestLength = longestLengthTemp;
        longestLengthTemp = 0;
        sb = new StringBuffer();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ')') {
                if (sb.length() == 0) {
                    if (longestLength < longestLengthTemp) {
                        longestLength = longestLengthTemp;
                    }
                }

                sb.append(s.charAt(i));
            } else {
                if (sb.length() <= 0) {
                    if (longestLength < longestLengthTemp) {
                        longestLength = longestLengthTemp;
                    }
                    longestLengthTemp = 0;
                    continue;
                }
                sb.deleteCharAt(sb.length() - 1);
                longestLengthTemp += 2;

            }
        }
        return longestLength;
    }

    /**
     * 1. 53.29,72.27
     * 2. 优化了length的获取，以及longestlength和longestLengthTemp的对比。
     * 
     * @Author kaikai 2019年9月25日 下午11:37:57
     * @param s
     * @return
     */
    public int longestValidParentheses3(String s) {
        int longestLength = 0;
        int longestLengthTemp = 0;
        StringBuffer sb;

        sb = new StringBuffer();
        longestLengthTemp = 0;
        int sbLength = 0;
        int sLength = s.length();
        for (int i = 0; i < sLength; i++) {
            // 优化点
            sbLength = sb.length();
            // 优化点
            if (sbLength == 0) {
                if (longestLength < longestLengthTemp) {
                    longestLength = longestLengthTemp;
                }
            }
            if (s.charAt(i) == '(') {
                sb.append(s.charAt(i));
            } else {
                if (sbLength <= 0) {
                    longestLengthTemp = 0;
                    sb = new StringBuffer();
                    continue;
                }
                sb.deleteCharAt(sbLength - 1);
                longestLengthTemp += 2;

            }
        }
        if (sb.length() == 0 && longestLength < longestLengthTemp)
            longestLength = longestLengthTemp;
        longestLengthTemp = 0;
        sb = new StringBuffer();
        for (int i = sLength - 1; i >= 0; i--) {
            sbLength = sb.length();
            if (sbLength == 0) {
                if (longestLength < longestLengthTemp) {
                    longestLength = longestLengthTemp;
                }
            }
            if (s.charAt(i) == ')') {

                sb.append(s.charAt(i));
            } else {
                if (sbLength <= 0) {

                    longestLengthTemp = 0;
                    continue;
                }
                sb.deleteCharAt(sbLength - 1);
                longestLengthTemp += 2;

            }
        }
        return longestLength;
    }

    /**
     * 1. 完全可以将sb删掉。因为只要一个数字就搞定了计数。使用count替代sb，
     * 2. 时间： 99.91. 空间：92.2
     * 
     * @Author kaikai 2019年9月25日 下午11:42:53
     * @param s
     * @return
     */
    public int longestValidParentheses4(String s) {
        int longestLength = 0;
        int longestLengthTemp = 0;

        int count = 0;
        int sLength = s.length();
        for (int i = 0; i < sLength; i++) {
            if (count == 0 && longestLength < longestLengthTemp) {
                longestLength = longestLengthTemp;
            }
            if (s.charAt(i) == '(') {
                count++;
            } else {
                if (count <= 0) {
                    longestLengthTemp = 0;
                    continue;
                }
                count--;
                longestLengthTemp += 2;

            }
        }
        if (count == 0 && longestLength < longestLengthTemp)
            longestLength = longestLengthTemp;
        longestLengthTemp = 0;
        count = 0;
        for (int i = sLength - 1; i >= 0; i--) {
            if (count == 0 && longestLength < longestLengthTemp) {
                longestLength = longestLengthTemp;
            }
            if (s.charAt(i) == ')') {
                count++;
            } else {
                if (count <= 0) {
                    longestLengthTemp = 0;
                    continue;
                }
                count--;
                longestLengthTemp += 2;
            }
        }
        return longestLength;
    }

    /**
     * 简单测试，s.length和使用一个int作为其值，有何区别
     * 1. 99.91,86.65
     * 2. 时间不变。但是空间损耗增加了。
     * 
     * @Author kaikai 2019年9月25日 下午11:51:08
     * @param s
     * @return
     */
    public int longestValidParentheses5(String s) {
        int longestLength = 0;
        int longestLengthTemp = 0;

        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (count == 0 && longestLength < longestLengthTemp) {
                longestLength = longestLengthTemp;
            }
            if (s.charAt(i) == '(') {
                count++;
            } else {
                if (count <= 0) {
                    longestLengthTemp = 0;
                    continue;
                }
                count--;
                longestLengthTemp += 2;

            }
        }
        if (count == 0 && longestLength < longestLengthTemp)
            longestLength = longestLengthTemp;
        longestLengthTemp = 0;
        count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (count == 0 && longestLength < longestLengthTemp) {
                longestLength = longestLengthTemp;
            }
            if (s.charAt(i) == ')') {
                count++;
            } else {
                if (count <= 0) {
                    longestLengthTemp = 0;
                    continue;
                }
                count--;
                longestLengthTemp += 2;
            }
        }
        return longestLength;

    }

    /**
     * 1. 99.91, 95.05
     * 
     * @Author kaikai 2019年9月26日 上午12:22:12
     * @param s
     * @return
     */
    public int longestValidParentheses6(String s) {
        int longestLength = 0;
        int longestLengthTemp = 0;

        int count = 0;
        int sLength = s.length();
        for (int i = 0; i < sLength; i++) {
            if (count == 0 && longestLength < longestLengthTemp) {
                longestLength = longestLengthTemp;
            }
            if (s.charAt(i) == '(') {
                count++;
            } else {
                if (count <= 0) {
                    longestLengthTemp = 0;
                    count = 0;
                    continue;
                }
                count--;
                longestLengthTemp += 2;

            }
        }
        if (count == 0 && longestLength < longestLengthTemp)
            longestLength = longestLengthTemp;
        if (count != 0 && longestLengthTemp > longestLength) {
            longestLengthTemp = 0;
            count = 0;
            for (int i = sLength - 1; i >= 0; i--) {
                if (count == 0 && longestLength < longestLengthTemp) {
                    longestLength = longestLengthTemp;
                }
                if (s.charAt(i) == ')') {
                    count++;
                } else {
                    if (count <= 0) {
                        longestLengthTemp = 0;
                        count = 0;
                        continue;
                    }
                    count--;
                    longestLengthTemp += 2;
                }
            }
        }

        return longestLength;
    }

    /**
     * 1. 看的官方题解，第三种方法。自己实现的算是第四种(略微不同),一次遍历，而且很简洁。使用栈，特点在于放入栈的是index
     * 2. 然而，出乎意料，时间53.28；空间80.96.
     * 3. 是stack的操作。并没有看起来这么快。简洁只是表面。尽量不要用collection，这大概是启示，最好使用数组。
     * 
     * @Author kaikai 2019年9月26日 下午10:00:25
     * @param s
     * @return
     */
    public int longestValidParentheses7(String s) {
        int longestLength = 0;
        Stack<Integer> stack = new Stack<Integer>();
        // 1. 因为前后相减比真实长度少1; 2. 后面每次计算最大长度相减的都是对应的下标的上一个。
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    longestLength = Math.max(longestLength, i - stack.peek());
                }
            }
        }
        return longestLength;
    }

    /**
     * 1. 参考官方题解第二种解法。 跟人感觉动态规划是比较正规的解法。毕竟是通用的。主要是退到迭代公式。
     * 2. 97.08,83.06
     * 3. 使用temp代替i-dp[i-1]之后：99.88，81.71
     * 4. 自己直接用官方题解的第四种方法提交，也是99.88. 并没有上面自己写的快。
     * 
     * @Author kaikai 2019年9月26日 下午10:15:27
     * @param s
     * @return
     */
    public int longestValidParentheses8(String s) {
        int longestLength = 0;
        int[] dp = new int[s.length()];

        int temp;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                } else {
                    temp = i - dp[i - 1];
                    if (temp > 0 && s.charAt(temp - 1) == '(') {
                        dp[i] = dp[i - 1] + (temp >= 2 ? dp[temp - 2] + 2 : 2);
                    }
                }
                longestLength = Math.max(longestLength, dp[i]);
            }
        }
        return longestLength;
    }
```
