class Solution {
    public boolean isAnagram(String s, String t) {
  char[] a=new char[26];
        char[] b=new char[26];
        char[] a1=s.toCharArray();
        char[] a2=t.toCharArray();
        if (a1.length!=a2.length)
            return false;
       for (int i=0;i<a1.length;i++)
        {
            a[a1[i]-'a']++;
            b[a2[i]-'a']++;
        }
        for (int i=0;i<a.length;i++)
        {
            //if ((a[a1[i]-'a'])!=(b[a2[i]]-'a'))
            if (a[i]!=b[i])
            {
                return false;
            }
        }
        return true;

    }
}