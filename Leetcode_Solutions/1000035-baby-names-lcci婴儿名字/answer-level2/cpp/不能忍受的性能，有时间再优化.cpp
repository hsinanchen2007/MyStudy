![未命名图片.png](https://pic.leetcode-cn.com/809cb86eef182158cba390b71ae247fea02f8e861084906463d2debb184fe6ab-%E6%9C%AA%E5%91%BD%E5%90%8D%E5%9B%BE%E7%89%87.png)

并查集三板斧
1.初始化：各个节点都是自己的父节点
2.查找，要有路径压缩
3.合并,查找每个节点的顶层父节点如果不一样，就合并

并查集算法原理请见一个大牛链接：
链接一：xianghttps://zhuanlan.zhihu.com/p/93647900
链接二：https://blog.csdn.net/Golden_Knight/article/details/104760906

弄清楚并茶几算法基本原理，这道题剩下的就是字符串操作、STL的功夫了，直接上一个首次提交的矬代码，哈哈（后面载优化的）
```
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

/* 解析列表synonyms中(name1,name2)字符串 */
pair<string, string> paraseName(string &synonym) {
	pair<string, string> p;
	int size = synonym.size();
	string names = synonym.substr(1, size-2);//去括号首尾
	size_t found = names.find(',');//找到分隔符

	p.first = names.substr(0, found);
	p.second = names.substr(found + 1);
	return p;
}

//并查集步骤一：初始化,将所有的人的父节点置为自己,names和synonyms中所有名字都要考虑 
void init(map<string, string> &father_map, vector<string>& names, vector<string>& synonyms, map<string, int> &names_count_map) {
	for (auto e : names) {
		int size = e.size();
		size_t found = e.find('(');
		string name = e.substr(0, found);
		string count_str = e.substr(found + 1, size - 2 - found);
		int count = atoi(count_str.c_str());
		names_count_map.insert({name, count});
		if (father_map.count(name) == 0) { //新名字
			father_map.insert({ name,name });
		}
	}

	for (auto synonym : synonyms) {
		pair<string, string> p = paraseName(synonym);
		if (father_map.count(p.first) == 0) { //新名字
			father_map.insert({ p.first,p.first });
		}
		if (father_map.count(p.second) == 0) { //新名字
			father_map.insert({p.second, p.second});
		}
	}
	
}

//并查集步骤二：查找顶层父节点，路径压缩
string findFather(string &name, map<string, string> &father_map) {
	if (father_map[name] == name) {
		return name;
	}
	father_map[name] = findFather(father_map[name], father_map); //路径压缩
	return father_map[name];
}

//并查集步骤三：
void combine(map<string, string> &father_map, vector<string>& synonyms){
	for (auto synonym : synonyms) {
		pair<string, string> p = paraseName(synonym);
		string fa1 = findFather(p.first, father_map);
		string fa2 = findFather(p.second, father_map);
		if (fa1 != fa2) {//如果顶层父节点不一样，就将fa1的父节点指向fa2
			father_map[fa1] = fa2;
		}
	}
}

vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
	vector<string> res;
	map<string, vector<string>> big_map;
	map<string, string>  father_map; //统计父节点
	map<string, int> names_count_map; //统计频率

	//1.初始化
	init(father_map, names, synonyms, names_count_map);

	//2.查找、合并
	combine(father_map, synonyms);

	//3.统计有几个真名字(帮主)及成员
	for (auto a : father_map) {
		string n = a.first;
		string f = findFather(n, father_map);
		if (big_map.count(f) == 0) {
			vector<string> vec_tmp = { n };
			big_map.insert({ f,vec_tmp });
		}
		else {
			big_map[f].push_back(n);
		}
	}

	for (auto a : big_map) {
		int cnt = 0;
		string name = a.first;
		vector<string> &vec = a.second;

		for (auto s : vec) {
			if (s < name) {
				name = s;
			}
			cnt += names_count_map[s];
		}
		string res_elem = name + "(" + to_string(cnt) + ")";
		res.push_back(res_elem);
	}

	return res;
}


int main() {
 
	vector<string> names1 = { "Iyk(99)", "Pffios(74)", "Uep(65)", "Ersd(71)", "Ahbxc(63)", "Ilzdj(100)", "Zotd(17)", "Zzqdz(47)", "Nhcljq(84)", "Czoihe(53)", "Opxvjg(49)", "Lxvf(36)", "Nsapy(29)", "Cxt(11)", "Cby(30)", "Wbfadk(76)", "Jyplq(5)", "Kbeprs(7)", "Cqkg(63)", "Svon(79)", "Pee(93)", "Rmei(5)", "Wezi(63)", "Ydq(28)", "Ehyeau(6)", "Wca(6)", "Hpaz(84)", "Fdgqd(16)", "Hnni(44)", "Jmol(58)", "Qwwfes(86)", "Azelz(89)", "Vpiyw(28)", "Vjrtp(73)", "Nbubog(61)", "Ljej(3)", "Dnb(93)", "Awvxx(99)", "Whrf(8)", "Jsg(72)", "Nqb(45)", "Lmqbsu(10)", "Noz(5)", "Kfik(47)", "Jfra(7)", "Oqn(31)", "Zkzy(75)", "Ivdvvb(1)", "Ickf(81)", "Apgsct(55)", "Aifwp(86)", "Uejp(96)", "Lnnwwa(48)", "Kdui(1)", "Ykfat(62)", "Vfudbh(88)", "Ugv(98)", "Pkrx(15)", "Efhhc(32)", "Fqu(34)", "Jvllh(32)", "Oozlsf(33)", "Szhtw(3)", "Ckhpam(26)", "Zre(6)", "Oacgib(80)", "Tmxwed(57)", "Qauc(74)", "Gfkey(34)", "Pnfl(52)", "Xnt(31)", "Ugi(74)", "Kslgzt(24)", "Pvhkyf(96)", "Jro(83)", "Tuvew(84)", "Bkckjx(95)", "Ybnj(44)", "Jyqhzn(84)", "Lmzxd(95)", "Rncxnf(83)", "Ylaxky(89)", "Hdvdlv(54)", "Lqzftw(44)", "Bbjvov(97)", "Urzekv(82)", "Girize(74)", "Ply(74)", "Meky(22)", "Bgsfw(47)", "Dnvbu(36)", "Ebg(11)", "Kjmvr(22)", "Qdyuu(14)", "Jvr(87)", "Wnycm(53)", "Irxb(71)", "Qrc(68)", "Trli(89)", "Low(96)"};
	vector<string> names2 = { "(Iyk,Ilzdj)", "(Ilzdj,Ykfat)", "(Lmzxd,Jvr)", "(Hpaz,Zre)", "(Whrf,Pvhkyf)", "(Whrf,Xnt)", "(Cby,Ugv)", "(Ydq,Jmol)", "(Vpiyw,Kdui)", "(Zre,Trli)", "(Ehyeau,Fqu)", "(Uejp,Jro)", "(Pkrx,Zre)", "(Vjrtp,Gfkey)", "(Ahbxc,Ehyeau)", "(Qwwfes,Kjmvr)", "(Cqkg,Pnfl)", "(Qwwfes,Ybnj)", "(Qauc,Bkckjx)", "(Kdui,Zre)", "(Iyk,Svon)", "(Lxvf,Fqu)", "(Wca,Jvllh)", "(Pkrx,Urzekv)", "(Nbubog,Ugi)", "(Tmxwed,Bbjvov)", "(Cxt,Ckhpam)", "(Ehyeau,Ckhpam)", "(Nhcljq,Jyqhzn)", "(Hpaz,Jmol)", "(Kjmvr,Wnycm)", "(Hnni,Whrf)", "(Nhcljq,Ickf)", "(Vjrtp,Fqu)", "(Ljej,Zkzy)", "(Uejp,Meky)", "(Vjrtp,Girize)" };
	
	vector<string> res = trulyMostPopular(names1, names2);
	return 0;
}



```
代码块
```

```
