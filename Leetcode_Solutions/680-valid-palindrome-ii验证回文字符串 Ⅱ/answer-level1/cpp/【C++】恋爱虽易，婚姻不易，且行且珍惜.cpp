
```
class Solution {
public:
    bool validPalindrome(string s) {
        int boy = 0;
        int girl = s.size() - 1;
        loveStory = s;
        
        while (!marriedWithYou(boy, girl)) {
            if (happyWithYou(boy, girl)) {
                prepareForNextDate(&boy, &girl);
            } else {
                
                return makeUpTheirDifferences(dateWithYoungerWomenFailed(boy), girl) || 
                    makeUpTheirDifferences(boy, dateWithRicherMenFailed(girl));    
            }
        }
        return true;
    }
private:
    bool marriedWithYou(int boy, int girl) {
        return boy >= girl; 
    }
    
    bool happyWithYou(int boy, int girl) {
        return loveStory[boy] == loveStory[girl];
    }
    
    void prepareForNextDate (int *boy, int *girl) {
        (*boy)++;
        --(*girl);
    }
    
    int dateWithYoungerWomenFailed(int boy) {
        return ++boy; 
    }
    
    int dateWithRicherMenFailed(int girl) {
        return --girl; 
    }
    
    bool makeUpTheirDifferences(int boy, int girl) {
        while (!marriedWithYou(boy, girl)) {
            if (happyWithYou(boy, girl)) {
                prepareForNextDate(&boy, &girl);
                continue;
            }
            return false;
        }
        return true;
    }
private:
    string loveStory;
};

```
