class Solution(object):
    def reverseWords(self, s):
       l = s.split(' ')
       m=""
       for member in l:
           if member =='' or member == ' ':
               l.remove(member)
       while l:
           member = l.pop()
           if member != '' and member != ' ':
               m +=  member
           else:
               continue
           if l:
               m +=' '
       return (m)
       