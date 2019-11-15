#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length) //можно создать вектор с положительной длиной
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector) //не может создать слишком большой вектор
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length) //ќшибка при создании вектора с отрицательной длиной
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex) //ќшибка при создании вектора с отрицательным начальным индексом
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector) //ћожно создать скопированный вектор
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

/*------------------------------------------------------------------------------------------*/

TEST(TVector, copied_vector_is_equal_to_source_one) //—копированный вектор равен исходному
{
	TVector<int> v1(15,3);
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory) //—копированный вектор имеет собственную пам€ть
{
	TVector<int> v1(15,3);
	TVector<int> v2(v1);
	EXPECT_NE(&v1, &v2);

	/*TVector<int> original(10);
	TVector<int> copy(original);
	EXPECT_EQ(false, &original[0] == &copy[0]);*/
}

TEST(TVector, can_get_size) //ћожно получить размер
{
  TVector<int> v(6);
  EXPECT_EQ(6, v.GetSize());
}

TEST(TVector, can_get_start_index) //ћожно получить начальный индекс
{
  TVector<int> v(4, 2);
  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element) //ћожно установить и получить элемент
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index) //ќшибка, когда задан элемент с отрицательным индексом
{
	TVector<int> v(5, 3);
	ASSERT_ANY_THROW(v[-1] = 15);
}

TEST(TVector, throws_when_set_element_with_too_large_index) //ќшибка, когда установлен элемент со слишком большим индексом
{
	TVector<int> v(5, 1);
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE + 1] = 15);
}

TEST(TVector, can_assign_vector_to_itself) //ћожет назначить вектор себе
{
	TVector<int> v(5);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size) //ћожно назначить векторы одинакового размера
{
	TVector<int> v1(6, 1), v2(6, 1);
	v1[1] = 1;
	v1[2] = 2;
	v2[1] = 3;
	v2[2] = 2;
	v2 = v1;
	EXPECT_EQ(v1,v2);
}

TEST(TVector, assign_operator_change_vector_size) //Ќазначить оператор изменени€ размера вектора
{
	TVector<int> v1(10, 1), v2(5, 1);
	v1 = v2;
	EXPECT_EQ(v1.GetSize(), 5);
}

TEST(TVector, can_assign_vectors_of_different_size) //ћожно назначить векторы разного размера
{
	TVector<int> v1(10, 1), v2(5, 1);
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true) //—равнить равные векторы вернуть true
{
	TVector<int> v1(10, 1), v2(10, 1);
	v1[1] = 1;
	v1[2] = 2;
	v2[1] = 1;
	v2[2] = 2;
	EXPECT_EQ(v1 == v2, true);
}

TEST(TVector, compare_vector_with_itself_return_true) //—равнить вектор с самим собой вернуть true
{
	TVector<int> v(3, 1);
	v[1] = 1;
	v[2] = 2;
	EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal) //¬екторы с разным размером не равны
{
	TVector<int> v1(3,1), v2(4,1);
	EXPECT_EQ(v1 == v2, false);
}

TEST(TVector, can_add_scalar_to_vector) //ћожно добавить скал€р к вектору
{
	TVector<int> v1(3, 1), v2(3, 1);
	v1[1] = 1;	
	v2[1] = 4;
	v1[2] = 2;	
	v2[2] = 5;
	EXPECT_EQ(v1 + 3, v2);
}

TEST(TVector, can_subtract_scalar_from_vector) //ћожно вычесть скал€р из вектора
{
	TVector<int> v1(3, 1), v2(3, 1);
	v1[1] = 1;	
	v2[1] = -2;
	v1[2] = 2;	
	v2[2] = -1;
	EXPECT_EQ(v1 - 3, v2);
	const int size = 10;
}

TEST(TVector, can_multiply_scalar_by_vector) //ћожно умножить скал€р на вектор
{
	TVector<int> v1(3, 1), v2(3, 1);
	v1[1] = 1;	
	v2[1] = 3;
	v1[2] = 2;	
	v2[2] = 6;
	EXPECT_EQ(v1 * 3, v2);
}

TEST(TVector, can_add_vectors_with_equal_size) //ћожно добавить векторы с одинаковым размером
{
	TVector<int> v1(3, 1), v2(3, 1), v3(3, 1);
	v1[1] = 1;	
	v1[2] = 2;	
	v2[1] = 1;
	v2[2] = 1;
	v3[1] = 2;
	v3[2] = 3;
	EXPECT_EQ(v1 + v2, v3);
}

TEST(TVector, cant_add_vectors_with_not_equal_size) //Ќе могу добавить векторы с не равным размером
{
	TVector<int> v1(3,1), v2(4,1);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size) //ћожет вычитать векторы с одинаковым размером
{
	TVector<int> v1(3, 1), v2(3, 1), v3(3, 1);
	v1[1] = 1;	
	v1[2] = 2;
	v2[1] = -1;
	v2[2] = -1;
	v3[1] = 2;
	v3[2] = 3;
	EXPECT_EQ(v1 - v2, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) //Ќе могу вычесть векторы с не равным размером
{
	TVector<int> v1(3,1), v2(4,1);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size) //ћожет умножать векторы с одинаковым размером
{
	TVector<int> v1(3), v2(3);
	v1[0] = 2;
	v1[1] = 2;
	v2[0] = 3;
	v2[1] = 2;
	EXPECT_EQ(v1 * v2, 10);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) //Ќе могу умножить векторы с не равным размером
{
	TVector<int> v1(3,1), v2(4,1);
	ASSERT_ANY_THROW(v1 * v2);
}

