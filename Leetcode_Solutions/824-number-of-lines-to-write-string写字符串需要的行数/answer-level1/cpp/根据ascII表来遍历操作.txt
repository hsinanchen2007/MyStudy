class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
		int eachSum = 0, lineNumber = 1;
        char number;
		for (int i = 0; i < S.size(); i++){
			number = (S.at(i) - 97);//'a'的值为97
			if ((eachSum + widths.at(number)) > 100){
				lineNumber++;
				eachSum = widths.at(number);
			}
			else{
				eachSum += widths.at(number);
			}
		}
		return{ lineNumber, eachSum };
    }
};