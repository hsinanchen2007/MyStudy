### 解题思路
此处撰写解题思路

### 代码

```c

int longestValidParentheses(char * s) {
    int start = 0, end = 0, index = 0, max = 0, curr = 0;
    int leftCount = 0, rightCount = 0;
    bool isAdding = false;
    int isNeeding = 0;
    if (s == NULL || strlen(s) < 2)
    {
        return 0;
    }

    for (index = 0; index < strlen(s); index++)
    {
        if (s[index] == '(' && isAdding == false)
        {
            start = index;  
            isAdding = true;
        }

        if (s[index] == '(' && isAdding == true)
        {
            leftCount += 1;
        }

        if (s[index] == ')' && isAdding == true)
        {
            if (leftCount > 0)
            {
                leftCount -= 1;
                if (leftCount == 0)
                {
                    curr = index - start + 1;
                    if (curr > max)
                    {
                        max = curr;
                    }
                }
            }
            else
            {
                isAdding = false;
            }
        }
    }
  
    isAdding = false;
    for (index = strlen(s) - 1; index > 0; index--)
    {
        if (s[index] == ')' && isAdding == false)
        {
            end = index;
            isAdding = true;
        }

        if (s[index] == ')' && isAdding == true)
        {
            rightCount += 1;
        }

        if (s[index] == '(' && isAdding == true)
        {
            if (rightCount > 0)
            {
                rightCount -= 1;
                if (rightCount == 0)
                {
                    curr = end - index + 1;
                    if (curr > max)
                    {
                        max = curr;
                    }
                }
            }
            else
            {
                isAdding = false;
            }
        }
    }

    return max;
}
```