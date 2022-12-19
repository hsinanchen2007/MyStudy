class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        mo = [".-" ,"-..." ,"-.-." ,"-.." ,"." ,"..-." ,"--." ,"...." ,".." ,".---" ,"-.-" ,".-.." ,"--" ,"-." ,"---"
          ,".--." ,"--.-" ,".-." ,"..." ,"-" ,"..-" ,"...-" ,".--" ,"-..-" ,"-.--" ,"--.."]
        se = set()
        for s in words:
            a = mo[ord(s[0])-97]
            for i in range(1,len(s)):
                a = a + mo[ord(s[i])-97]
            se.add(a)
        return len(se)