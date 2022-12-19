第一次看的时候没有思路，看了题解以后才恍然大悟，原来这道题和之前做的一道题实质上是一样的，但自己忽略了字符型和int型的关系。过了几天又看的时候有了一种新的思路。
class Solution {
    public char findTheDifference(String s, String t) {
        char[] ch1=s.toCharArray();
        char[] ch2=t.toCharArray();
        Arrays.sort(ch1);
        Arrays.sort(ch2);
        for(int i=0;i<ch1.length;i++){
            if(ch1[i]!=ch2[i]){
                return ch2[i];
            }
        }
        return ch2[ch2.length-1];
    }
}
首先将两个字符串分别转为字符数组，然后对他们排序，由于只有一个不同，所以排序后只需要找到那个不同的数就可以了。如果循环没有找到那个不同的数，则说明该数在t的尾部，直接返回该字符就可以