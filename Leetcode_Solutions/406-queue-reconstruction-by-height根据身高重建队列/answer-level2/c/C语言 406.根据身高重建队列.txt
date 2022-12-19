```
int comp2(const void* a, const void* b)
{
        int *an = *(int **)a;
        int *bn = *(int **)b;
        if (an[0] == bn[0])
                return an[1] - bn[1];
        return an[0] - bn[0];
}
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
        *returnColumnSizes = peopleColSize;
        *returnSize = peopleSize;
        if (people == NULL || peopleSize == 0) return NULL;
        int index = 0;
        bool isnot[peopleSize];
        memset(isnot, true, sizeof(isnot));
        qsort(people, peopleSize, sizeof(int) * 2, comp2);
        for (index = 0; index < peopleSize; index++) {
                if (!isnot[index]) continue;
                int i = people[index][1];
                int ptr = 0;
                while(i > 0) {
                        if(people[ptr][0] >= people[index][0] && ptr != index)
                                i--;
                        ptr++;
                }
                int mov[2] = { 0 };
                mov[0] = people[index][0], mov[1] = people[index][1];
                int last = index;
                for (int j = index + 1; j < ptr; j++)
                        if (isnot[j]) {
                                people[last][0] = people[j][0], people[last][1] = people[j][1];
                                last = j;
                        }
                people[last][0] = mov[0], people[last][1] = mov[1];
                isnot[last] = false;
                if (last != index) index--;
        }   
        return people;
}
```
