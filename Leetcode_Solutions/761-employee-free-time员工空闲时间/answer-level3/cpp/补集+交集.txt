先求补集再求交集 很好理解的方法 c++ 536ms 50%
```cpp
class Solution {
public:
	vector<Interval*> complementary(vector<Interval*>& schedule) {
		vector<Interval*> result;
		int prev = INT_MIN;
		int ptr = 0;
		while (ptr != schedule.size()) {
			result.push_back(new Interval(prev, schedule[ptr]->start));
			prev = schedule[ptr]->end;
			ptr++;
		}
		result.push_back(new Interval(prev, INT_MAX));
		return result;
	}

	vector<Interval*> combineIntervals(vector<Interval*>& A, vector<Interval*>& B) {
		vector<Interval*> result;
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 < A.size() && ptr2 < B.size()) {
			if (A[ptr1]->start > B[ptr2]->start) {
				if (A[ptr1]->start < B[ptr2]->end)
					if (result.size() != 0 && result.back()->end > A[ptr1]->start)
						result.back()->end = min(result.back()->end, A[ptr1]->end);
					else
						result.push_back(new Interval(A[ptr1]->start, min(A[ptr1]->end, B[ptr2]->end)));
			}
			else {
				if (B[ptr2]->start < A[ptr1]->end)
					if (result.size() != 0 && result.back()->end > B[ptr2]->start)
						result.back()->end = min(result.back()->end, B[ptr2]->end);
					else
						result.push_back(new Interval(B[ptr2]->start, min(A[ptr1]->end, B[ptr2]->end)));
			}
			if (A[ptr1]->end >= B[ptr2]->end)
				ptr2++;
			else
				ptr1++;
		}
		return result;
	}

	vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
		for (vector<Interval*>& i : schedule)
			i = complementary(i);
		for (int i = 1; i < schedule.size(); ++i)
			schedule[0] = combineIntervals(schedule[0], schedule[i]);
        vector<Interval*> result;
        for (int i = 1; i < schedule[0].size() - 1; ++i)
            result.push_back(schedule[0][i]);
		return result;
	}
};
```
