#include <iostream>

/*
 * ����N����������ɶ��ٸ�����������
 * ����ÿһ��N, ���Ե�֪���ڵ��������������ΪL_CNT[0, N-1), ������������Ϊ[N-1, 0��
 * �ֱ�����û������¿�����ɶ��ٸ�����������
 */

//�ǵݹ����
class Solution {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1) return 1;

		int* cnt = new int[n + 1];
		cnt[0] = 1;
		cnt[1] = 1;

		for (int i = 2; i <= n; ++i)
		{
			int subTreeCnt = 0;
			for (int j = 0; j < i; ++j)
			{
				int lSubTreeCnt = cnt[j];
				int rSubTreeCnt = cnt[i - 1 - j];
				subTreeCnt += lSubTreeCnt * rSubTreeCnt;
			}
			cnt[i] = subTreeCnt;
		}

		int ret = cnt[n];
		delete []cnt;
		return ret;
	}
};

//�ݹ����
class Solution_2 {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1) return 1;

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cnt += numTrees(i) * numTrees(n - 1 - i);
		}
		return cnt;
	}
};

int main()
{
	Solution s;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " " << s.numTrees(i) << std::endl;
	}

	Solution_2 s2;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " " << s2.numTrees(i) << std::endl;
	}
	return 0;
}