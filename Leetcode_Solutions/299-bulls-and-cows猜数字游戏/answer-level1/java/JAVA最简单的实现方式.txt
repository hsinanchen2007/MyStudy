    其实很简单，只是题目如果没有读懂会比较让人痛苦。公牛没有争议，奶牛的计算是需要刨除掉公牛的。拿1123和0111来说，为什么奶牛是1呢，这是因为虽然0111中除掉第二个1，还有两个1，但是1123中除掉第二个公牛的1，只剩下一个1可以和0111中的奶牛配对了。所以这个例子奶牛是1.1122和2211的奶牛是4.

public static String getHint(String secret, String guess) {
        String res = "";
        int a = 0;
        List<Character> list = new ArrayList<Character>();
        List<Character> listse = new ArrayList<Character>();
        int b = secret.length();
        char[] x1 = secret.toCharArray();
        char[] x2 = guess.toCharArray();
        for (int i = 0; i < b; i++) {
            if (x1[i] == x2[i]) {
                a++;
            } else {
                listse.add(x1[i]);
                list.add(x2[i]);
            }
        }
        int c = list.size();
        int d = 0;
        for (int i = 0; i < c; i++) {
            int e = listse.indexOf(list.get(i));
            if (e >= 0) {
                d++;
                listse.remove(e);
            }
        }
        res = a + "A" + d + "B";
        return res;
    }