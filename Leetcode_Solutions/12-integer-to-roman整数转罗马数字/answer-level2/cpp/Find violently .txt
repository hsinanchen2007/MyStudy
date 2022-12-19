class Solution{
public:
    string intToRoman(int num){
        string va;
        vector<int>y{0,1,2,3,4,5,6,7,8,9};
        vector<string>tb{"","M","MM","MMM"};//thousand bit case
        vector<string>hb{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};//hundred bit case
        vector<string>db{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};//decade bit case
        vector<string>nb{"","I","II","III","IV","V","VI","VII","VIII","IX"};//number bit case
        va+=sb[find(y.begin(),y.begin()+3,num/1000)-y.begin()];//subtract thousand bit
        va+=hb[find(y.begin(),y.end(),num/100%10)-y.begin()];//subtract hundred bit
        va+=db[find(y.begin(),y.end(),num/10%10)-y.begin()];//subtract decade bit
        va+=nb[find(y.begin(),y.end(),num%10)-y.begin()];//subtract number bit
        return va;//increase value and return
    }
};
//As a newer,reference plz.