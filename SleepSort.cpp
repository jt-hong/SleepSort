#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
void CountDown(int);
std::vector <int> Sorted;
int main()
{
	std::vector <std::thread> Threads;
	int NumList[] = { 10,4,12,56,22,45, 34,8,98,43 };
	for (int i = 0; i <= 10; i++)
	{
		Threads.push_back(std::thread(CountDown, NumList[i]));
	}
	for (auto& thread : Threads)
	{
		thread.join();
	}
	for (auto& Num : Sorted)
	{
		std::cout << Num<<std::endl;
	}
    return 0;
}

void CountDown(int Sec)
{
	std::this_thread::sleep_for(std::chrono::seconds(Sec));
	Sorted.push_back(Sec);
}