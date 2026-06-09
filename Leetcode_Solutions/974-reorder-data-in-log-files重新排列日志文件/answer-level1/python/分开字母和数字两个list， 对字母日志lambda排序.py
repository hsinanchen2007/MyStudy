1. seperate letter log and digit log
2. sort letter log
3. combine two lists
```
class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        # split the log into letters and digits
        letters = []
        digits = []
        for log in logs:
            log_list = log.split(' ')
            if log_list[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
        
        letters.sort(key = lambda log: (log.split(' ')[1:], log.split(' ')[0]))
        return letters + digits
```
