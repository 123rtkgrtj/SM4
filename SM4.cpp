#include<iostream>
#include<string>
using namespace std;
const string fk[4] = { "A3B1BAC6","56AA3350","677D9197","B27022DC" };
const string ck[32] = { "00070E15","1C232A31","383F464D","545B6269","70777E85","8C939AA1","A8AFB6BD","C4CBD2D9",
						"E0E7EEF5","FC030A11","181F262D","343B4249","50575E65","6C737A81","888F969D","A4ABB2B9",
						"C0C7CED5","DCE3EAF1","F8FF060D","141B2229","30373E45","4C535A61","686F767D","848B9299",
						"A0A7AEB5","BCC3CAD1","D8DFE6ED","F4FB0209","10171E25","2C333A41","484F565D","646B7279" };
const string S[256] = { "D6","90","E9","FE","CC","E1","3D","B7","16","B6","14","C2",
						"28","FB","2C","05","2B","67","9A","76","2A","BE","04","C3",
						"AA","44","13","26","49","86","06","99","9C","42","50","F4",
						"91","EF","98","7A","33","54","0B","43","ED","CF","AC","62",
						"E4","B3","1C","A9","C9","08","E8","95","80","DF","94","FA",
						"75","8F","3F","A6","47","07","A7","FC","F3","73","17","BA",
						"83","59","3C","19","E6","85","4F","A8","68","6B","81","B2",
						"71","64","DA","8B","F8","EB","0F","4B","70","56","9D","35",
						"1E","24","0E","5E","63","58","D1","A2","25","22","7C","3B",
						"01","21","78","87","D4","00","46","57","9F","D3","27","52",
						"4C","36","02","E7","A0","C4","C8","9E","EA","BF","8A","D2",
						"40","C7","38","B5","A3","F7","F2","CE","F9","61","15","A1",
						"E0","AE","5D","A4","9B","34","1A","55","AD","93","32","30",
						"F5","8C","B1","E3","1D","F6","E2","2E","82","66","CA","60",
						"C0","29","23","AB","0D","53","4E","6F","D5","DB","37","45",
						"DE","FD","8E","2F","03","FF","6A","72","6D","6C","5B","51",
						"8D","1B","AF","92","BB","DD","BC","7F","11","D9","5C","41",
						"1F","10","5A","D8","0A","C1","31","88","A5","CD","7B","BD",
						"2D","74","D0","12","B8","E5","B4","B0","89","69","97","4A",
						"0C","96","77","7E","65","B9","F1","09","C5","6E","C6","84",
						"18","F0","7D","EC","3A","DC","4D","20","79","EE","5F","3E",
						"D7","CB","39","48" };
string turn2(string a)//十六进制转二进制
{
	string b = "";
	if (a == "0")
		b = "0000";
	else if (a == "1")
		b = "0001";
	else if (a == "2")
		b = "0010";
	else if (a == "3")
		b = "0011";
	else if (a == "4")
		b = "0100";
	else if (a == "5")
		b = "0101";
	else if (a == "6")
		b = "0110";
	else if (a == "7")
		b = "0111";
	else if (a == "8")
		b = "1000";
	else if (a == "9")
		b = "1001";
	else if (a == "A")
		b = "1010";
	else if (a == "B")
		b = "1011";
	else if (a == "C")
		b = "1100";
	else if (a == "D")
		b = "1101";
	else if (a == "E")
		b = "1110";
	else if (a == "F")
		b = "1111";
	return b;
}
string allturn2(string a)//字符串转二进制
{
	string b = "";
	for (int i = 0; i < a.size(); i++)
		b = b + turn2(a.substr(i, 1));
	return b;
}
int turn10(string a)//二进制转十进制
{
	int b = 0;
	if (a == "0000")
		b = 0;
	else if (a == "0001")
		b = 1;
	else if (a == "0010")
		b = 2;
	else if (a == "0011")
		b = 3;
	else if (a == "0100")
		b = 4;
	else if (a == "0101")
		b = 5;
	else if (a == "0110")
		b = 6;
	else if (a == "0111")
		b = 7;
	else if (a == "1000")
		b = 8;
	else if (a == "1001")
		b = 9;
	else if (a == "1010")
		b = 10;
	else if (a == "1011")
		b = 11;
	else if (a == "1100")
		b = 12;
	else if (a == "1101")
		b = 13;
	else if (a == "1110")
		b = 14;
	else if (a == "1111")
		b = 15;
	return b;
}
string turn16(string a)//字符串转十六进制
{
	string b = "";
	string c = "0123456789ABCDEF";
	for (int i = 0; i < a.size() / 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (turn2(c.substr(j,1)) == a.substr(4 * i, 4))
				b = b + c.substr(j,1);
		}
	}
	return b;
}
string leftmove(string a, int b)//左移运算
{
	string c = "";
	c = a.substr(b) + a.substr(0, b);
	return c;
}
string yihuo(string a, string b)//异或运算
{
	if (a == b)
		return "0";
	else
		return "1";
}
string yihuoall(string a, string b)//多位字符串异或
{
	string c = "";
	for (int i = 0; i < a.size(); i++)
		c = c + yihuo(a.substr(i, 1), b.substr(i, 1));
	return c;
}
string t1(string a, string b, string c, string d)//密钥扩展的T置换
{
	string e = "";
	e = yihuoall(yihuoall(a, b), yihuoall(c, d));
	string f = "";
	for (int i = 0; i < 4; i++)
		f = f + S[turn10(e.substr(8 * i, 4)) * 16 + turn10(e.substr(8 * i + 4, 4))];
	f = allturn2(f);
	return yihuoall(yihuoall(f, leftmove(f, 13)), leftmove(f, 23));
}
string t2(string a, string b, string c, string d)//加密中的T置换
{
	string e = "";
	e = yihuoall(yihuoall(a, b), yihuoall(c, d));
	string f = "";
	for (int i = 0; i < 4; i++)
		f = f + S[turn10(e.substr(8 * i, 4)) * 16 + turn10(e.substr(8 * i + 4, 4))];
	f = allturn2(f);
	return yihuoall(yihuoall(yihuoall(f, leftmove(f, 2)), yihuoall(leftmove(f, 10), leftmove(f, 18))), leftmove(f, 24));
}
string sm4(string a, string b)//SM4加密
{
	string p = allturn2(a);
	string q = allturn2(b);
	string rk[32] = {};
	string k[36] = {};
	string x[36] = {};
	k[0] = yihuoall(q.substr(0, 32), allturn2(fk[0]));
	k[1] = yihuoall(q.substr(32, 32), allturn2(fk[1]));
	k[2] = yihuoall(q.substr(64, 32), allturn2(fk[2]));
	k[3] = yihuoall(q.substr(96, 32), allturn2(fk[3]));
	for (int i = 0; i < 32; i++)
	{
		k[i + 4] = yihuoall(k[i], t1(k[i + 1], k[i + 2], k[i + 3], allturn2(ck[i])));
		rk[i] = k[i + 4];
	}
	x[0] = p.substr(0, 32);
	x[1] = p.substr(32, 32);
	x[2] = p.substr(64, 32);
	x[3] = p.substr(96, 32);
	for (int i = 0; i < 32; i++)
		x[i + 4] = yihuoall(x[i], t2(x[i + 1], x[i + 2], x[i + 3], rk[i]));
	string c = "";
	c = x[35] + x[34] + x[33] + x[32];
	return c;
}
int main()
{
	string a, b;
	cout << "明文：";
	cin >> a;
	cout << "密钥：";
	cin >> b;
	cout << "密文："<< turn16(sm4(a, b));
}
