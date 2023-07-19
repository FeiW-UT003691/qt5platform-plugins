// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include <gtest/gtest.h>
#include <QWindow>
#include <QDebug>

#include "dnativesettings.h"

DPP_USE_NAMESPACE

class TDNativeSettings : public testing::Test
{
protected:
    void SetUp();
    void TearDown();

    QWindow *window;
};

void TDNativeSettings::SetUp()
{
    window = new QWindow;
}

void TDNativeSettings::TearDown()
{
    delete window;
}

TEST_F(TDNativeSettings, getSettingsProperty)
{
    QByteArray array = DNativeSettings::getSettingsProperty(window);
    qWarning() << array;
    window->setProperty("_d_domain", "/test/test");
    array = DNativeSettings::getSettingsProperty(window);
    ASSERT_EQ(array, "_TEST_TEST");
}


