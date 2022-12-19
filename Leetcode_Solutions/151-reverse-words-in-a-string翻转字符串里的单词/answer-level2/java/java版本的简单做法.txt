 public String reverseWords(String s) {
	String[] words = new String[] {};
	String temp = s.trim();
	System.out.println("ori==>" + s);
	System.out.println("trim==>" + temp);
	words = temp.split("\\s+");

	StringBuilder sb = new StringBuilder();
	for (int i = 0, l = words.length; i < l; i++) {
	    System.out.println(words[i]);
	    sb.append(words[l - 1 - i]);
	    sb.append(" ");
	}
	return sb.toString();
    }

测试中加了输出信息，便于debug，粗体是结果。
ori==>  the sky     is   blue!!
trim==>the sky     is   blue!!
the
sky
is
blue!!
**str=>blue!! is sky the**
ori==>   hello   world!   
trim==>hello   world!
hello
world!
**str1=>world! hello** 
ori==>  a good    example  
trim==>a good    example
a
good
example
**str2=>example good a**
ori==>  a s f   g      
trim==>a s f   g
a
s
f
g
**str3=>g f s a**
