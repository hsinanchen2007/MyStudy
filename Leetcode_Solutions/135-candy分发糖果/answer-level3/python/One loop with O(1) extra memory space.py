See comments.

The key here is:
1. add back/remove extra right line of the hill
2. add an duplicated last element to unify the process.

```python
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        sz = len(ratings)
        if sz == 0:
            return 0
        if sz == 1:
            return 1

        # duplicate last element, to unify the processing
        last = ratings[-1]
        ratings.append(last)

        total = 1
        prev_pos = 0 # previous stop position, it's hill position
        curr_val = 1 # current's val, it could be either positive, or negative, we would adjust based on it
        for i in range(1, len(ratings)):
            if ratings[i] >= ratings[i-1]:
                if prev_pos == i - 1:
                    # adjust the prev pointer to current
                    if ratings[i] == ratings[i-1]:
                        curr_val = 1
                    else:
                        curr_val += 1
                else:
                    # till prev_pos to i-1, it's a down direction

                    # TODO:
                    #print('found')
                    # now, curr val is i-1's value
                    if curr_val > 1:
                        # remove the extra number from total
                        # we shall remove number from [prev_pos+1, i-1], each remove (curr_val-1)
                        total -= (i-1-prev_pos-1+1) * (curr_val - 1)
                        #print('remove extra from ' + str([prev_pos+1, i-1]) + ' with each value ' + str(curr_val-1))
                    elif curr_val < 1:
                        # add back the number to total
                        # we shall add number from [prev_pos, i-1], each add (1-curr_val)
                        total += (i-1-prev_pos+1) * (1 - curr_val)
                        #print('add back from ' + str([prev_pos, i-1]) + ' with each value ' + str(1-curr_val))
                    
                    if ratings[i] == ratings[i-1]:
                        # this is equal to previous, so this should have value 1 started
                        curr_val = 1
                    else:
                        # this is bigger than previous, and previous is just the valley, so
                        # this would begin with 2
                        curr_val = 2
                prev_pos = i
                total += curr_val
            else:
                curr_val -= 1
                total += curr_val
            #print(str(i) + ':' + str([prev_pos, curr_val]))
        # remove the ending extra one
        return total - 1
```
