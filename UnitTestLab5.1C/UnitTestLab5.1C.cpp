#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.1C++/Lab5.1C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51C
{
	TEST_CLASS(UnitTestLab51C)
	{
	public:
		
		TEST_METHOD(TestMethod1)

		{
			char f[6] = "f.dat";
			char g[6] = "g.dat";
			ProcessBin(f, g);
		}
	};
}
