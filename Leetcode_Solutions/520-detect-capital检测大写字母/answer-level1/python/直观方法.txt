class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        dictWord =  {"a":0,"b":0,"c":0,"d":0,"e":0,"f":0,"g":0,"h":0,"i":0,"j":0,
              "k":0,"l":0,"m":0,"n":0,"o":0,"p":0,"q":0,"r":0,
			  "s":0,"t":0,"u":0,"v":0,"w":0,"x":0,"y":0,"z":0,
			  "A":1,"B":1,"C":1,"D":1,"E":1,"F":1,"G":1,"H":1,"I":1,
			  "J":1,"K":1,"L":1,"M":1,"N":1,"O":1,"P":1,"Q":1,
			  "R":1,"S":1,"T":1,"U":1,"V":1,"W":1,"X":1,"Y":1,"Z":1}
        #0为小写 非0为大写
        #加起来全为0  加起来为1且只有首字母为1  全部加起来为n*1
        re = 0
        for s in word:
            re += dictWord[s]
        if re == 0 or re == len(word) or (re==1 and dictWord[word[0]] == 1):
            return True
        else:
            return False
        